cmake_minimum_required(VERSION 3.8)
project(ros2_launch_demo)

# Compiler settings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# ===============================
# Build executables
# ===============================

add_executable(talker src/talker.cpp)
add_executable(listener src/listener.cpp)

# Link dependencies
ament_target_dependencies(talker
  rclcpp
  std_msgs
)

ament_target_dependencies(listener
  rclcpp
  std_msgs
)

# ===============================
# Install executables
# ===============================

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME}
)

# ===============================
# Install launch files
# ===============================

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# ===============================
# Finalize package
# ===============================

ament_package()
