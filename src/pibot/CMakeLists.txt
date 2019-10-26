cmake_minimum_required(VERSION 2.8.3)
project(pibot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  roslib
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

add_library(pibot_hl_lib 
	include/lane_hl/lane_hl.h
	src/lane_hl/lane_hl.cpp
	src/lane_hl/hough.cpp
)

add_library(pibot_ipm_lib 
	include/lane_ipm/lane_ipm.h
	src/lane_ipm/lane_ipm.cpp
)

add_executable(pibot src/cam/main.cpp)
target_link_libraries(pibot pibot_lib ${OpenCV_LIBS} ${catkin_LIBRARIES} )

add_executable(pibot_hl src/lane_hl/main.cpp)
target_link_libraries(pibot_hl pibot_lib pibot_hl_lib ${OpenCV_LIBS} ${catkin_LIBRARIES} )

add_executable(pibot_ipm src/lane_ipm/main.cpp)
target_link_libraries(pibot_ipm pibot_lib pibot_ipm_lib ${OpenCV_LIBS} ${catkin_LIBRARIES} )

catkin_install_python(PROGRAMS scripts/motor.py
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

