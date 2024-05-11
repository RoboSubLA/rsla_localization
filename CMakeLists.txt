cmake_minimum_required(VERSION 3.5)
project(localization)  # This should match your package name

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Include C++ libraries
include_directories(include)

# Create executable
add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp geometry_msgs)

add_executable(listener2 src/listener2.cpp)  # Add listener2 executable
ament_target_dependencies(listener2 rclcpp geometry_msgs)  # Dependency for listener2

# Install executable
install(TARGETS listener
  listener2
  DESTINATION lib/${PROJECT_NAME})

ament_package()
