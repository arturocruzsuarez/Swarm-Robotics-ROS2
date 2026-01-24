#include "srvED_Team_Movement.h"

srvTeamMovement::srvTeamMovement(double x, double y, Miscelaneo * misc_): srvEvaluateDriver(x,y,misc) // hay que agregar el id del robot que le corresponda
{

    RCLCPP_INFO(this->get_logger(), "Servidor de Team Movement listo para recibir solicitudes.");
    misc=misc_;
}

srvTeamMovement::~srvTeamMovement()
{
}

bool srvTeamMovement::evaluateDriver(const shared_ptr<arlo_interfaces::srv::EvaluateDriver::Request> request,
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

    startSimulation(request->maxtime);

    response->time = arloState.finishTime;
    response->dist2go = arloState.distanceToGo;
    response->damage = arloState.robotDamage;
    response->energy = arloState.distanceTravelled;
    response->dist2mates = arloState.dist_to_mates;

    return true;
}

SimulationState srvTeamMovement::startSimulation(int maxtime)
{

    puts("Starting the simulation of a new driver...");
    puts("---------------------------");

    arloState.resetState();
    double fx = 0;
    maxSimTime = maxtime;
    num_check = 0;

    stuckCounter = 0;

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

            fx = maxSimTime + arloState.distanceToGo + arloState.dist_to_mates;
        }
        else
        { // The robot reached the goal.
            arloState.finishTime = arloState.currentTime;

            arloState.distanceToGo = 0.0;
            arloState.robotEnergy = 100;
            cout << "finishTime = " << arloState.finishTime << "\n" << endl;
            fx = arloState.finishTime + arloState.dist_to_mates;
        }

    cout << "x = " << arloState.position[0] << ", y = " << arloState.position[1] << endl;
    cout << "d2Go = " << arloState.distanceToGo << endl;
    cout << "gas = " << arloState.distanceTravelled << endl;
    cout << "dist_to_mates = " << arloState.dist_to_mates << endl;
    cout << "fx = " << fx << endl;

    cout << "Bye." << endl;

    return arloState;
}


void srvTeamMovement::checkModelPosition(const arlo_interfaces::msg::EstadoArlo &msg)
{
    // ROS_INFO("Seq: [%d]", msg->header.seq);
    // ROS_INFO("Position-> x: [%f]", msg->pose.pose.position.x);
    // ROS_INFO("Vel-> Linear: [%f], Angular: [%f]",
    //		msg->twist.twist.linear.x,
    //		msg->twist.twist.angular.z);

    // arloState.currentPosition = msg->pose.pose.position.x;
    // if (arloState.currentPosition >= goalDistance)   // Esta es la distancia del pasillo en Gazebo.
    // 	arloState.finishLineCrossed = true;

    double distanceBefore = arloState.distanceTravelled;
    arloState.distanceTravelled += distance(prev_x, prev_y, msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);

    if (abs(distanceBefore - arloState.distanceTravelled) < 0.01)
    {
        stuckCounter++;
        // cout << "Stuck counter: " << stuckCounter << "\n";
        if (stuckCounter > 20)
        {
            arloState.stuck = true;
            arloState.hasTimeRunOut = true;
        }
    }
    else
        stuckCounter = 0;

    prev_x = msg.odom.pose.pose.position.x;
    prev_y = msg.odom.pose.pose.position.y;

    arloState.currentPosition = msg.odom.pose.pose.position.x;
    arloState.position[0] = msg.odom.pose.pose.position.x;
    arloState.position[1] = msg.odom.pose.pose.position.y;
    // cerr << "x: " << arloState.position[0] << " y: " << arloState.position[1] << endl;
    // double d2go = dist2Go(msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);
    arloState.distanceToGo = dist2Go(msg.odom.pose.pose.position.x, msg.odom.pose.pose.position.y);

    dist_to_mates(msg.dist_to_mates);

    if (arloState.distanceToGo <= 1.0) arloState.finishLineCrossed = true;
}

void srvTeamMovement::dist_to_mates(double current_dist_to_mates){
    arloState.dist_to_mates = (arloState.dist_to_mates+current_dist_to_mates) / 2;
}
// void srvEvaluateDriver::IgnoreSetter(const std_msgs::msg::Int64::SharedPtr msg){
//     ignoreFlag = msg->data;
// }

// int srvEvaluateDriver::getNumSensors() {
// 	return NUM_RAYS * NUM_SONARS;
// }

// int srvEvaluateDriver::getNumActuators() {
// 	return NUM_ACTUATORS;
// }
// rclcpp::Service<arlo_interfaces::srv::EvaluateDriver>::SharedPtr service_;
