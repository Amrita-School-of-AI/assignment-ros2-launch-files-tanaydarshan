[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/2fCSFxR1)
# Assignment: ROS2 Launch Files

**Course:** ROS2 Fundamentals  
**Build System:** ament_cmake

## Objective

The goal of this assignment is to verify your understanding of:

1. How to create ROS2 launch files using Python.
2. How to launch multiple nodes together.
3. How to pass parameters through launch files.
4. How to remap topics in launch files.

## Problem Statement

You must complete the provided skeleton code to create a launch file that starts a publisher and subscriber together with configured parameters.

### Requirements

1. **Publisher Node (`src/talker.cpp`)**:
   - Already provided (complete implementation).
   - Publishes to `/chatter` topic.
   - Has parameter `message_prefix` (default: "Hello").

2. **Subscriber Node (`src/listener.cpp`)**:
   - Already provided (complete implementation).
   - Subscribes to `/chatter` topic.

3. **Launch File (`launch/pubsub.launch.py`)**:
   Create a launch file that:
   - Launches the `talker` node with:
     - Parameter `message_prefix` set to `"ROS2"`
   - Launches the `listener` node.
   - Both nodes should be in the same package `ros2_launch_demo`.

4. **Build Configuration (`CMakeLists.txt`)**:
   - Install the launch directory.

## How to Test Locally

```bash
colcon build --packages-select ros2_launch_demo
source install/setup.bash
ros2 launch ros2_launch_demo pubsub.launch.py
```

#### Expected Output:

```shell
[talker]: Publishing: 'ROS2: 0'
[listener]: I heard: 'ROS2: 0'
[talker]: Publishing: 'ROS2: 1'
[listener]: I heard: 'ROS2: 1'
...
```
