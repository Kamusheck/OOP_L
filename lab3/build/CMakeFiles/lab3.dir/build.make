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

# Include any dependencies generated for this target.
include CMakeFiles/lab3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3.dir/flags.make

CMakeFiles/lab3.dir/src/hexagon.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/src/hexagon.cpp.o: ../src/hexagon.cpp
CMakeFiles/lab3.dir/src/hexagon.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3.dir/src/hexagon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/src/hexagon.cpp.o -MF CMakeFiles/lab3.dir/src/hexagon.cpp.o.d -o CMakeFiles/lab3.dir/src/hexagon.cpp.o -c /root/OOP_L/lab3/src/hexagon.cpp

CMakeFiles/lab3.dir/src/hexagon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/src/hexagon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/OOP_L/lab3/src/hexagon.cpp > CMakeFiles/lab3.dir/src/hexagon.cpp.i

CMakeFiles/lab3.dir/src/hexagon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/src/hexagon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/OOP_L/lab3/src/hexagon.cpp -o CMakeFiles/lab3.dir/src/hexagon.cpp.s

CMakeFiles/lab3.dir/src/method.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/src/method.cpp.o: ../src/method.cpp
CMakeFiles/lab3.dir/src/method.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab3.dir/src/method.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/src/method.cpp.o -MF CMakeFiles/lab3.dir/src/method.cpp.o.d -o CMakeFiles/lab3.dir/src/method.cpp.o -c /root/OOP_L/lab3/src/method.cpp

CMakeFiles/lab3.dir/src/method.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/src/method.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/OOP_L/lab3/src/method.cpp > CMakeFiles/lab3.dir/src/method.cpp.i

CMakeFiles/lab3.dir/src/method.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/src/method.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/OOP_L/lab3/src/method.cpp -o CMakeFiles/lab3.dir/src/method.cpp.s

CMakeFiles/lab3.dir/src/pentagon.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/src/pentagon.cpp.o: ../src/pentagon.cpp
CMakeFiles/lab3.dir/src/pentagon.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab3.dir/src/pentagon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/src/pentagon.cpp.o -MF CMakeFiles/lab3.dir/src/pentagon.cpp.o.d -o CMakeFiles/lab3.dir/src/pentagon.cpp.o -c /root/OOP_L/lab3/src/pentagon.cpp

CMakeFiles/lab3.dir/src/pentagon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/src/pentagon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/OOP_L/lab3/src/pentagon.cpp > CMakeFiles/lab3.dir/src/pentagon.cpp.i

CMakeFiles/lab3.dir/src/pentagon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/src/pentagon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/OOP_L/lab3/src/pentagon.cpp -o CMakeFiles/lab3.dir/src/pentagon.cpp.s

CMakeFiles/lab3.dir/src/romb.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/src/romb.cpp.o: ../src/romb.cpp
CMakeFiles/lab3.dir/src/romb.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab3.dir/src/romb.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/src/romb.cpp.o -MF CMakeFiles/lab3.dir/src/romb.cpp.o.d -o CMakeFiles/lab3.dir/src/romb.cpp.o -c /root/OOP_L/lab3/src/romb.cpp

CMakeFiles/lab3.dir/src/romb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/src/romb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/OOP_L/lab3/src/romb.cpp > CMakeFiles/lab3.dir/src/romb.cpp.i

CMakeFiles/lab3.dir/src/romb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/src/romb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/OOP_L/lab3/src/romb.cpp -o CMakeFiles/lab3.dir/src/romb.cpp.s

CMakeFiles/lab3.dir/main.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/main.cpp.o: ../main.cpp
CMakeFiles/lab3.dir/main.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab3.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/main.cpp.o -MF CMakeFiles/lab3.dir/main.cpp.o.d -o CMakeFiles/lab3.dir/main.cpp.o -c /root/OOP_L/lab3/main.cpp

CMakeFiles/lab3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/OOP_L/lab3/main.cpp > CMakeFiles/lab3.dir/main.cpp.i

CMakeFiles/lab3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/OOP_L/lab3/main.cpp -o CMakeFiles/lab3.dir/main.cpp.s

# Object files for target lab3
lab3_OBJECTS = \
"CMakeFiles/lab3.dir/src/hexagon.cpp.o" \
"CMakeFiles/lab3.dir/src/method.cpp.o" \
"CMakeFiles/lab3.dir/src/pentagon.cpp.o" \
"CMakeFiles/lab3.dir/src/romb.cpp.o" \
"CMakeFiles/lab3.dir/main.cpp.o"

# External object files for target lab3
lab3_EXTERNAL_OBJECTS =

lab3: CMakeFiles/lab3.dir/src/hexagon.cpp.o
lab3: CMakeFiles/lab3.dir/src/method.cpp.o
lab3: CMakeFiles/lab3.dir/src/pentagon.cpp.o
lab3: CMakeFiles/lab3.dir/src/romb.cpp.o
lab3: CMakeFiles/lab3.dir/main.cpp.o
lab3: CMakeFiles/lab3.dir/build.make
lab3: CMakeFiles/lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/OOP_L/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lab3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3.dir/build: lab3
.PHONY : CMakeFiles/lab3.dir/build

CMakeFiles/lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3.dir/clean

CMakeFiles/lab3.dir/depend:
	cd /root/OOP_L/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/OOP_L/lab3 /root/OOP_L/lab3 /root/OOP_L/lab3/build /root/OOP_L/lab3/build /root/OOP_L/lab3/build/CMakeFiles/lab3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab3.dir/depend

