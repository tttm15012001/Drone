# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tttm/catkin_ws/src/mavlink

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tttm/catkin_ws/build/mavlink

# Utility rule file for uAvionix.xml-v2.0.

# Include the progress variables for this target.
include CMakeFiles/uAvionix.xml-v2.0.dir/progress.make

CMakeFiles/uAvionix.xml-v2.0: uAvionix-v2.0-cxx-stamp


uAvionix-v2.0-cxx-stamp: /home/tttm/catkin_ws/src/mavlink/message_definitions/v1.0/uAvionix.xml
uAvionix-v2.0-cxx-stamp: /home/tttm/catkin_ws/src/mavlink/message_definitions/v1.0/common.xml
uAvionix-v2.0-cxx-stamp: /home/tttm/catkin_ws/src/mavlink/pymavlink/tools/mavgen.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/tttm/catkin_ws/build/mavlink/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating uAvionix-v2.0-cxx-stamp"
	/usr/bin/env PYTHONPATH="/home/tttm/catkin_ws/src/mavlink:/opt/ros/noetic/lib/python3/dist-packages" /usr/bin/python3.8 /home/tttm/catkin_ws/src/mavlink/pymavlink/tools/mavgen.py --lang=C++11 --wire-protocol=2.0 --output=include/v2.0 /home/tttm/catkin_ws/src/mavlink/message_definitions/v1.0/uAvionix.xml
	touch uAvionix-v2.0-cxx-stamp

uAvionix.xml-v2.0: CMakeFiles/uAvionix.xml-v2.0
uAvionix.xml-v2.0: uAvionix-v2.0-cxx-stamp
uAvionix.xml-v2.0: CMakeFiles/uAvionix.xml-v2.0.dir/build.make

.PHONY : uAvionix.xml-v2.0

# Rule to build all files generated by this target.
CMakeFiles/uAvionix.xml-v2.0.dir/build: uAvionix.xml-v2.0

.PHONY : CMakeFiles/uAvionix.xml-v2.0.dir/build

CMakeFiles/uAvionix.xml-v2.0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uAvionix.xml-v2.0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uAvionix.xml-v2.0.dir/clean

CMakeFiles/uAvionix.xml-v2.0.dir/depend:
	cd /home/tttm/catkin_ws/build/mavlink && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tttm/catkin_ws/src/mavlink /home/tttm/catkin_ws/src/mavlink /home/tttm/catkin_ws/build/mavlink /home/tttm/catkin_ws/build/mavlink /home/tttm/catkin_ws/build/mavlink/CMakeFiles/uAvionix.xml-v2.0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uAvionix.xml-v2.0.dir/depend

