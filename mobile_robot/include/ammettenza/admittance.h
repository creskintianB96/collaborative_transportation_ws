#ifndef ADMITTANCE_H_
#define ADMITTANCE_H_
#define _USE_MATH_DEFINES
#include <ros/ros.h>
#include <ros/package.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/WrenchStamped.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>
#include <control_msgs/JointTrajectoryControllerState.h>

// tf
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <tf2/convert.h>
#include <tf2_eigen/tf2_eigen.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// MoveIt!
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>

// KDL
#include <kdl/chain.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainjnttojacsolver.hpp>

//Eigen
#include <eigen3/Eigen/Core>
#include <Eigen/Eigen>

//#include <eigen3/Eigen/Core>
#include <Eigen/Eigen>


extern "C" {
    #include "solver.h"
}

typedef Eigen::Matrix<double, 6, 6> Matrix6d;
typedef Eigen::Matrix<double, 4, 4> Matrix4d;
typedef Eigen::Matrix<double, 6, 2> Matrix62d;
typedef Eigen::Matrix<double, 2, 6> Matrix26d;
typedef Eigen::Matrix<double, 6, 8> Matrix68d;
typedef Eigen::Matrix<double, 8, 6> Matrix86d;
typedef Eigen::Matrix<double, 8, 8> Matrix8d;
typedef Eigen::Matrix<double, 8, 1> Vector8d;
typedef Eigen::Matrix<double, 6, 1> Vector6d;
typedef Eigen::Matrix<double, 4, 1> Vector4d;
typedef Eigen::Matrix<double, 3, 1> Vector3d;
typedef Eigen::Matrix<double, 2, 1> Vector2d;


class Admittance {

    public:
      Admittance();
      ~Admittance();

      void OdometryCallback(const nav_msgs::Odometry& msg);
      void RuoteCallback(const sensor_msgs::JointState& msg);
      void JointStateCallback(const sensor_msgs::JointState::ConstPtr &);
      void joystickCallback(const sensor_msgs::Joy& msg);
      Matrix4d compute_arm_fk (double joint_position[], double joint_velocity[]);
      Eigen::MatrixXd compute_arm_jacobian (double joint_position[], double joint_velocity[]);
      Matrix62d compute_platform_jacobian(double rotation);
      Matrix6d Arm_Mapping(double rotation);
      Matrix6d Mir_Mapping(double rotation);
      Matrix6d Transformata(double rotation, int num);
      Vector8d SatNullSpace(Vector6d cartesian_velocity, Eigen::MatrixXd system_jacobian, Vector8d Vel_LowerLimit, Vector8d Vel_UpperLimit);
      Vector8d limit_joints_dynamics (Vector8d joint_velocity);
            //Vector8d found_joint_limits (Vector8d joint_velocity);
      int sign (double num);

      void Spinner();

      Eigen::MatrixXd jacobian_arm_kdl;
      Matrix6d Transform_ee_platform;
      Matrix6d Transform_platform_b;
      Matrix6d Transform_b_odom;
      Matrix6d ee_mapping_matrix;


      Eigen::Matrix3d Rot_ArmBase_Platform;
      Eigen::Matrix3d Rot_Platform_b;
      Eigen::Matrix3d Rot_b_World;

      Vector3d W_r_B_E;

      Vector6d F_ext;
      Matrix6d M_tot, D_tot;
      Vector8d acc_limits;
      Vector8d vel_limits;
      //Matrix8d M_tot_prova, D_tot_prova;

      double cycle_time;
      double roll, pitch, yaw;
      double vel_x, omega_z;
      //define the wheel radius and the lenght of wheel's  axis
      double R, L, b_;
      double omega_l, omega_r;

      double roll_ee, pitch_ee, yaw_ee;


      double joint_real_position[6];
      double joint_real_velocity[6];

      Vector6d twist;


      trajectory_msgs::JointTrajectory arm_message;
      geometry_msgs::Twist base_message;
      geometry_msgs::WrenchStamped force_message;
      std_msgs::Float32 energia;

      //lunghezza del braccio
      double lunghezza;

      Eigen::Vector3d ee_pose_kdl;

      Vector8d adm_twist_last_cycle;
      Vector8d q_dot_SNS_last_cycle;
      //Vector8d q_dot_SNS;
      //Vector8d Vel_LowerLimit;
        //Vector8d Vel_UpperLimit;
      Vector8d Acc_LowerLimit;
      Vector8d Acc_UpperLimit;
      Vector8d Max_Limits;
      Vector8d Min_Limits;
      Vector8d opt_qdot_prev;


      //############## Tank Variables ##############//

      double sum_of_delta_;
      float tank_state_;
      float tank_energy_;
      const float TANK_INITIAL_VALUE = 6.0; // was 20
      const float TANK_MAX_VALUE = 500.0;
      const float TANK_MIN_VALUE = 5.0;


    private:

      ros::NodeHandle nh;
      //Subscribers
      ros::Subscriber odometry_sub;
      ros::Subscriber joystick_sub;
      ros::Subscriber joints_state_sub;
      //Publishers
      ros::Publisher arm_pub;
            ros::Publisher mobile_pub;
      ros::Publisher force_node;
      ros::Publisher tank_node;



      sensor_msgs::JointState joint_state;

      double x_ee_platform, y_ee_platform, z_ee_platform;
      double x_platform, y_platform, z_platform;

      std::ofstream q_dot_SNS_file;
      std::ofstream q_dot_file;
      std::ofstream force_file;
      std::ofstream q_dot_opt_file;
      std::ofstream tank_file;

      // ---- MoveIt Robot Model ---- //
      robot_model_loader::RobotModelLoader robot_model_loader;
      robot_model::RobotModelPtr kinematic_model;
      robot_state::RobotStatePtr kinematic_state;
      const robot_state::JointModelGroup *joint_model_group;
      std::vector<std::string> joint_names;


};

#endif /* ADMITTANCE_H_ */

