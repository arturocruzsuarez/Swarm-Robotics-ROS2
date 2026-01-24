#include "srvED_Multiple_Goals.h"

srvMultipleGoals::srvMultipleGoals(double x, double y, Miscelaneo *misc_): srvEvaluateDriver(x,y,misc) //Node("servidor_simulacion_Multiple_Goals")
{
    rclcpp::QoS qos_profile(1);
    // Cambiar la política de confiabilidad a 'Best Effort'
    qos_profile.reliability(rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);

    service_ = this->create_service<arlo_interfaces::srv::EvaluateDriver>("evaluate_driver",
                                                                          bind(&srvMultipleGoals::evaluateDriver, this, placeholders::_1, placeholders::_2));

    UpdateGoal= this->create_publisher<std_msgs::msg::Float64MultiArray>("robot10/changeGoal", 10);

    RCLCPP_INFO(this->get_logger(), "Servidor de MultipleGoals listo para recibir solicitudes.");

    prev_x = 0;
    prev_y = 0;
    stuck = false;
    stuckCounter = 0;
    num_check = 0;
    x_start = -6.6;
    y_start = -13.6;

    gen = mt19937(random_device{}());
    gen.seed(rd());
    uniform_dist = uniform_int_distribution<>(1, goals_2_reach - 1);

    misc = misc_;

    //cerr << "hola" << endl;
}

srvMultipleGoals::~srvMultipleGoals() {}

bool srvMultipleGoals::evaluateDriver(const shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
                                       const shared_ptr<arlo_interfaces::srv::EvaluateDriver::Response> response)
{
    // arloState.resetState();
    auto flag = std_msgs::msg::Int64();
    flag.data = 1;
    ignoreSetter->publish(flag);

    string pesos = request->weightsfile;
    auto mensaje = std_msgs::msg::String();
    mensaje.data = pesos;
    publisher_pesos_eval->publish(mensaje);

    misc->restartSimulation();

    while ((arloState.position[0] > x_start) || (arloState.position[1] > y_start))
    {
        executor->spin_node_once(nodoOdom);
        RCLCPP_INFO(this->get_logger(), "Esperando a que los datos estén bien");
        cerr << arloState.position[0] << arloState.position[1] << endl;
    }

    flag.data = 0;
    ignoreSetter->publish(flag);

    current_goal_xy = GoalsCoordenates[0];

    startSimulation(request->maxtime);

    response->time = arloState.finishTime;
    response->dist2go = arloState.distanceToGo;
    response->damage = arloState.robotDamage;
    response->energy = arloState.distanceTravelled;
    response->dist2mates = arloState.dist_to_mates;

    return true;
}

SimulationState srvMultipleGoals::startSimulation(int maxTime)
{

    puts("Starting the simulation of a new driver with multiple goals...");
    puts("---------------------------");

    arloState.resetState();
    double fx = 0;
    double goalsUnreached=goals_2_reach;
    std_msgs::msg::Float64MultiArray vector_Goal;
    maxSimTime = maxTime*goals_2_reach;
    num_check = 0;


    stuckCounter = 0;

    while (goalsUnreached > 0)
    {
        while (rclcpp::ok() && !arloState.hasTimeRunOut && !arloState.finishLineCrossed)
        {
            executor->spin_node_once(nodoClock);
            executor->spin_node_once(nodoOdom);
        }

        cout << "hasTimeRunOut= " << arloState.hasTimeRunOut << "\n";
        cout << "finishLineCrossed= " << arloState.finishLineCrossed << "\n";

        if (arloState.hasTimeRunOut == true)
        {
            arloState.finishTime = 2 * maxSimTime;
            // arloState.distanceToGo = goalDistance - arloState.currentPosition;
            cout << "currentPosition= " << arloState.currentPosition << "\n";
            if (arloState.stuck == true)
            {
                cout << " ---->>> ATASCADO  <<<-----" << endl;
                cout << " \t Counter = " << stuckCounter << endl;
            }
            fx = ((maxSimTime/timerWIndow) + arloState.distanceToGo)*goalsUnreached;
            cerr << "saliendo " << endl;
            break;
        }
        else
        { // The robot reached the goal.
            arloState.finishTime = arloState.currentTime;
            arloState.distanceToGo = 0.0;
            arloState.robotEnergy = 100;
            cout << "finishTime = " << arloState.finishTime << "\n" << endl;
            fx = arloState.finishTime;
        }
        timerWIndow++;
        goalsUnreached--;
        arloState.resetState();

        current_goal_xy = GoalsCoordenates[uniform_dist(this->gen)];
        cout << current_goal_xy.first << "" << current_goal_xy.second << endl;

        vector_Goal.data.push_back(current_goal_xy.first);
        vector_Goal.data.push_back(current_goal_xy.second);

        UpdateGoal->publish(vector_Goal);

        misc->SetEntityState(current_goal_xy.first, current_goal_xy.second, 0.15, "cerebral_carpet",
                             "src/cognitive_architecture/models/cerebral_carpet/cerebral_carpet.sdf");

    }

    cout << "x = " << arloState.position[0] << ", y = " << arloState.position[1] << endl;
    cout << "d2Go = " << arloState.distanceToGo << endl;
    cout << "gas = " << arloState.distanceTravelled << endl;
    // cout << "dist_to_mates = " << arloState.dist_to_mates << endl;
    cout << "fx = " << fx << endl;

    cout << "Bye." << endl;

    return arloState;
}


void srvMultipleGoals::checkSimulationTime(const rosgraph_msgs::msg::Clock &msg)
{
    arloState.currentTime = msg.clock.sec;

    if (arloState.currentTime >= (maxSimTime/goals_2_reach)*timerWIndow) arloState.hasTimeRunOut = true;
}