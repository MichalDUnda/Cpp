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
include prototype/CMakeFiles/prototype.dir/depend.make

# Include the progress variables for this target.
include prototype/CMakeFiles/prototype.dir/progress.make

# Include the compile flags for this target's objects.
include prototype/CMakeFiles/prototype.dir/flags.make

prototype/CMakeFiles/prototype.dir/main.cpp.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/main.cpp.o: ../prototype/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prototype/CMakeFiles/prototype.dir/main.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/main.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/prototype/main.cpp

prototype/CMakeFiles/prototype.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/main.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/prototype/main.cpp > CMakeFiles/prototype.dir/main.cpp.i

prototype/CMakeFiles/prototype.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/main.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/prototype/main.cpp -o CMakeFiles/prototype.dir/main.cpp.s

# Object files for target prototype
prototype_OBJECTS = \
"CMakeFiles/prototype.dir/main.cpp.o"

# External object files for target prototype
prototype_EXTERNAL_OBJECTS =

prototype/prototype: prototype/CMakeFiles/prototype.dir/main.cpp.o
prototype/prototype: prototype/CMakeFiles/prototype.dir/build.make
prototype/prototype: prototype/CMakeFiles/prototype.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prototype"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prototype.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prototype/CMakeFiles/prototype.dir/build: prototype/prototype

.PHONY : prototype/CMakeFiles/prototype.dir/build

prototype/CMakeFiles/prototype.dir/clean:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype && $(CMAKE_COMMAND) -P CMakeFiles/prototype.dir/cmake_clean.cmake
.PHONY : prototype/CMakeFiles/prototype.dir/clean

prototype/CMakeFiles/prototype.dir/depend:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michaldunda/Projects/ownProjects/C++/firstPattern /home/michaldunda/Projects/ownProjects/C++/firstPattern/prototype /home/michaldunda/Projects/ownProjects/C++/firstPattern/build /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/prototype/CMakeFiles/prototype.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prototype/CMakeFiles/prototype.dir/depend

