cmake_minimum_required(VERSION 2.8.3)
project(mavros_test)

add_definitions(-Wall -std=c++11)

find_package(catkin REQUIRED COMPONENTS
  mavros
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES mavros_test
#  CATKIN_DEPENDS mavros roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)