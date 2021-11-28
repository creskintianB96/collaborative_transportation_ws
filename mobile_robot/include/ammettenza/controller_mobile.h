#ifndef CONTROLLER_MOBILE_H_
#define CONTROLLER_MOBILE_H_
#define _USE_MATH_DEFINES
#include <ros/ros.h>
#include <cmath>
#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JointState.h>
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

#include <eigen3/Eigen/Core>
#include <Eigen/Eigen>

//#include <eigen3/Eigen/Core>
#include <Eigen/Eigen>

typedef Eigen::Matrix<double, 6, 6> Matrix6d;
typedef Eigen::Matrix<double, 6, 2> Matrix62d;
typedef Eigen::Matrix<double, 2, 6> Matrix26d;
typedef Eigen::Matrix<double, 2, 2> Matrix2d;
typedef Eigen::Matrix<double, 6, 1> Vector6d;
typedef Eigen::Matrix<double, 2, 1> Vector2d;
typedef Eigen::Array<double, 6, 1> Array6d;
typedef Eigen::Matrix<double, 3, 1> Vector3d;




class Controller_mobile {

		public:
			Controller_mobile();

			void OdometryCallback(const nav_msgs::Odometry& msg);
			void RuoteCallback(const sensor_msgs::JointState& msg);
			void joystickCallback(const sensor_msgs::Joy& msg);
			Matrix6d Transformata();
			Matrix62d compute_platform_jacobian(double rotation);
			Vector6d limit_cartesian_dynamics (Vector6d joint_velocity);
			Vector2d limit_wheels_dynamics(Vector2d wheel_velocity);
			int sign (double num);
            void Spinner();

			Eigen::MatrixXd F_ext;
			//Matrix6d M_tot, D_tot;
			Matrix2d M_tot_prova, D_tot_prova;

			double cycle_time;
			double roll, pitch, yaw;
            double vel_x, omega_z;
			//define the wheel radius and the lenght of wheel's  axis
			double R, L, b_;

			double omega_l, omega_r;

			Vector6d adm_twist_last_cycle;	

            ros::Publisher mobile_pub;
            geometry_msgs::Twist base_message;

		private:

			ros::NodeHandle nh;
			ros::Subscriber odometry_sub;
			ros::Subscriber joystick_sub;
			ros::Subscriber mir_joint_sub;

			//double roll, pitch, yaw;
			double x_ee_platform, y_ee_platform, z_ee_platform;
			double x_platform, y_platform, z_platform;

};

#endif /* CONTROLLER_MOBILE_H_ */

