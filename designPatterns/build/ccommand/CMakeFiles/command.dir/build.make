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
include ccommand/CMakeFiles/command.dir/depend.make

# Include the progress variables for this target.
include ccommand/CMakeFiles/command.dir/progress.make

# Include the compile flags for this target's objects.
include ccommand/CMakeFiles/command.dir/flags.make

ccommand/CMakeFiles/command.dir/ccommand.cpp.o: ccommand/CMakeFiles/command.dir/flags.make
ccommand/CMakeFiles/command.dir/ccommand.cpp.o: ../ccommand/ccommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ccommand/CMakeFiles/command.dir/ccommand.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/command.dir/ccommand.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/ccommand/ccommand.cpp

ccommand/CMakeFiles/command.dir/ccommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/command.dir/ccommand.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/ccommand/ccommand.cpp > CMakeFiles/command.dir/ccommand.cpp.i

ccommand/CMakeFiles/command.dir/ccommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/command.dir/ccommand.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/ccommand/ccommand.cpp -o CMakeFiles/command.dir/ccommand.cpp.s

# Object files for target command
command_OBJECTS = \
"CMakeFiles/command.dir/ccommand.cpp.o"

# External object files for target command
command_EXTERNAL_OBJECTS =

ccommand/command: ccommand/CMakeFiles/command.dir/ccommand.cpp.o
ccommand/command: ccommand/CMakeFiles/command.dir/build.make
ccommand/command: ccommand/CMakeFiles/command.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable command"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/command.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ccommand/CMakeFiles/command.dir/build: ccommand/command

.PHONY : ccommand/CMakeFiles/command.dir/build

ccommand/CMakeFiles/command.dir/clean:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand && $(CMAKE_COMMAND) -P CMakeFiles/command.dir/cmake_clean.cmake
.PHONY : ccommand/CMakeFiles/command.dir/clean

ccommand/CMakeFiles/command.dir/depend:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michaldunda/Projects/ownProjects/C++/firstPattern /home/michaldunda/Projects/ownProjects/C++/firstPattern/ccommand /home/michaldunda/Projects/ownProjects/C++/firstPattern/build /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/ccommand/CMakeFiles/command.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ccommand/CMakeFiles/command.dir/depend
