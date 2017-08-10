cmake_minimum_required(VERSION 2.8.3)
project(mavros_test)

add_definitions(-Wall -std=c++11)

find_package(catkin REQUIRED COMPONENTS
  mavros
  roscpp
  libmavconn
  std_msgs
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

if (CATKIN_ENABLE_TESTING)

catkin_add_gtest(mavconn-test src/mavconn-test.cxx)
target_link_libraries(mavconn-test ${catkin_LIBRARIES})

endif()

add_executable(serial-pixhawk src/serial-pixhawk.cxx)
target_link_libraries(serial-pixhawk ${catkin_LIBRARIES})