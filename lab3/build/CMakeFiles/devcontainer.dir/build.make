# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/OOP_L/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/OOP_L/lab3/build

# Utility rule file for devcontainer.

# Include any custom commands dependencies for this target.
include CMakeFiles/devcontainer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/devcontainer.dir/progress.make

CMakeFiles/devcontainer: lab3
CMakeFiles/devcontainer: tests

devcontainer: CMakeFiles/devcontainer
devcontainer: CMakeFiles/devcontainer.dir/build.make
.PHONY : devcontainer

# Rule to build all files generated by this target.
CMakeFiles/devcontainer.dir/build: devcontainer
.PHONY : CMakeFiles/devcontainer.dir/build

CMakeFiles/devcontainer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/devcontainer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/devcontainer.dir/clean

CMakeFiles/devcontainer.dir/depend:
	cd /root/OOP_L/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/OOP_L/lab3 /root/OOP_L/lab3 /root/OOP_L/lab3/build /root/OOP_L/lab3/build /root/OOP_L/lab3/build/CMakeFiles/devcontainer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/devcontainer.dir/depend

