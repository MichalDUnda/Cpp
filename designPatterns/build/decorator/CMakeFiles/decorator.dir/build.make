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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/local/lib/python3.6/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.6/dist-packages/cmake/data/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michaldunda/Projects/ownProjects/C++/firstPattern

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michaldunda/Projects/ownProjects/C++/firstPattern/build

# Include any dependencies generated for this target.
include decorator/CMakeFiles/decorator.dir/depend.make

# Include the progress variables for this target.
include decorator/CMakeFiles/decorator.dir/progress.make

# Include the compile flags for this target's objects.
include decorator/CMakeFiles/decorator.dir/flags.make

decorator/CMakeFiles/decorator.dir/decorator.cpp.o: decorator/CMakeFiles/decorator.dir/flags.make
decorator/CMakeFiles/decorator.dir/decorator.cpp.o: ../decorator/decorator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object decorator/CMakeFiles/decorator.dir/decorator.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/decorator.dir/decorator.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/decorator/decorator.cpp

decorator/CMakeFiles/decorator.dir/decorator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/decorator.dir/decorator.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/decorator/decorator.cpp > CMakeFiles/decorator.dir/decorator.cpp.i

decorator/CMakeFiles/decorator.dir/decorator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/decorator.dir/decorator.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/decorator/decorator.cpp -o CMakeFiles/decorator.dir/decorator.cpp.s

# Object files for target decorator
decorator_OBJECTS = \
"CMakeFiles/decorator.dir/decorator.cpp.o"

# External object files for target decorator
decorator_EXTERNAL_OBJECTS =

decorator/decorator: decorator/CMakeFiles/decorator.dir/decorator.cpp.o
decorator/decorator: decorator/CMakeFiles/decorator.dir/build.make
decorator/decorator: decorator/CMakeFiles/decorator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable decorator"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decorator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
decorator/CMakeFiles/decorator.dir/build: decorator/decorator

.PHONY : decorator/CMakeFiles/decorator.dir/build

decorator/CMakeFiles/decorator.dir/clean:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator && $(CMAKE_COMMAND) -P CMakeFiles/decorator.dir/cmake_clean.cmake
.PHONY : decorator/CMakeFiles/decorator.dir/clean

decorator/CMakeFiles/decorator.dir/depend:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michaldunda/Projects/ownProjects/C++/firstPattern /home/michaldunda/Projects/ownProjects/C++/firstPattern/decorator /home/michaldunda/Projects/ownProjects/C++/firstPattern/build /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/decorator/CMakeFiles/decorator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : decorator/CMakeFiles/decorator.dir/depend

