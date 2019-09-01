cmake_minimum_required(VERSION 2.8.3)
project(pi_ipbot)

find_package(catkin REQUIRED COMPONENTS
)

find_package(
   OpenCV REQUIRED
)

include_directories(include)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable( pi_ipbot src/main.cpp)
target_link_libraries(pi_ipbot ${OpenCV_LIBS} ${catkin_LIBRARIES} )

