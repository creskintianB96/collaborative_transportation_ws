# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/include/eigen3".split(';') if "${prefix}/include;/usr/include/eigen3" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;std_msgs;trajectory_msgs;geometry_msgs;sensor_msgs;moveit_core;moveit_ros_planning_interface;tf2_geometry_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lmobile_robot;-llibreria".split(';') if "-lmobile_robot;-llibreria" != "" else []
PROJECT_NAME = "mobile_robot"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.0.2"
