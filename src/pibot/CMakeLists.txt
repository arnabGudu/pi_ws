cmake_minimum_required(VERSION 2.8.3)
project(pibot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(
   OpenCV REQUIRED
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

include_directories(include)

add_library(pibot_lib 
	include/cam/cam.h
	include/pid/pid.h
	src/cam/cam.cpp
	src/pid/pid.cpp
)

add_executable(pibot src/main.cpp)
target_link_libraries(pibot pibot_lib ${OpenCV_LIBS} ${catkin_LIBRARIES} )

catkin_install_python(PROGRAMS scripts/motor.py
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

