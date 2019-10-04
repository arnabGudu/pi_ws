cmake_minimum_required(VERSION 2.8.3)
project(pi_ipbot)

FIND_LIBRARY(wiringPi wiringPi /home/Desktop/clone/wiringPi)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	wiringPi
)

find_package(OpenCV REQUIRED)

catkin_package(

)

include_directories(
	${catkin_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
)

add_executable( pi_ipbot src/main.cpp)
target_link_libraries(pi_ipbot ${OpenCV_LIBS} ${catkin_LIBRARIES} )

add_executable( gpio src/gpio.cpp)
target_link_libraries(gpio ${catkin_LIBRARIES} ${wiringPi} )

