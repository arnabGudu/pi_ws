cmake_minimum_required(VERSION 2.8.3)
project(pibot)

find_package(catkin REQUIRED COMPONENTS
  rospy
  genmsg
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(motor src/motor.py)
target_link_libraries(motor ${catkin_LIBRARIES})
