# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291

# Include any dependencies generated for this target.
include CMakeFiles/project4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project4.dir/flags.make

CMakeFiles/project4.dir/main.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project4.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project4.dir/main.cpp.o -c /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/main.cpp

CMakeFiles/project4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project4.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/main.cpp > CMakeFiles/project4.dir/main.cpp.i

CMakeFiles/project4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project4.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/main.cpp -o CMakeFiles/project4.dir/main.cpp.s

CMakeFiles/project4.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/project4.dir/main.cpp.o.requires

CMakeFiles/project4.dir/main.cpp.o.provides: CMakeFiles/project4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/project4.dir/main.cpp.o.provides

CMakeFiles/project4.dir/main.cpp.o.provides.build: CMakeFiles/project4.dir/main.cpp.o

CMakeFiles/project4.dir/ladder.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/ladder.cpp.o: ladder.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/project4.dir/ladder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/project4.dir/ladder.cpp.o -c /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/ladder.cpp

CMakeFiles/project4.dir/ladder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project4.dir/ladder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/ladder.cpp > CMakeFiles/project4.dir/ladder.cpp.i

CMakeFiles/project4.dir/ladder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project4.dir/ladder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/ladder.cpp -o CMakeFiles/project4.dir/ladder.cpp.s

CMakeFiles/project4.dir/ladder.cpp.o.requires:
.PHONY : CMakeFiles/project4.dir/ladder.cpp.o.requires

CMakeFiles/project4.dir/ladder.cpp.o.provides: CMakeFiles/project4.dir/ladder.cpp.o.requires
	$(MAKE) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/ladder.cpp.o.provides.build
.PHONY : CMakeFiles/project4.dir/ladder.cpp.o.provides

CMakeFiles/project4.dir/ladder.cpp.o.provides.build: CMakeFiles/project4.dir/ladder.cpp.o

# Object files for target project4
project4_OBJECTS = \
"CMakeFiles/project4.dir/main.cpp.o" \
"CMakeFiles/project4.dir/ladder.cpp.o"

# External object files for target project4
project4_EXTERNAL_OBJECTS =

project4: CMakeFiles/project4.dir/main.cpp.o
project4: CMakeFiles/project4.dir/ladder.cpp.o
project4: CMakeFiles/project4.dir/build.make
project4: CMakeFiles/project4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable project4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project4.dir/build: project4
.PHONY : CMakeFiles/project4.dir/build

CMakeFiles/project4.dir/requires: CMakeFiles/project4.dir/main.cpp.o.requires
CMakeFiles/project4.dir/requires: CMakeFiles/project4.dir/ladder.cpp.o.requires
.PHONY : CMakeFiles/project4.dir/requires

CMakeFiles/project4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project4.dir/clean

CMakeFiles/project4.dir/depend:
	cd /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291 /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291 /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291 /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291 /home/student/workspace/cmpe250-project4-abdullahyildiz2018400291/CMakeFiles/project4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project4.dir/depend
