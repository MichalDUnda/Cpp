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
include brokerChain/CMakeFiles/brokerChain.dir/depend.make

# Include the progress variables for this target.
include brokerChain/CMakeFiles/brokerChain.dir/progress.make

# Include the compile flags for this target's objects.
include brokerChain/CMakeFiles/brokerChain.dir/flags.make

brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.o: brokerChain/CMakeFiles/brokerChain.dir/flags.make
brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.o: ../brokerChain/brokerChain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brokerChain.dir/brokerChain.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/brokerChain/brokerChain.cpp

brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brokerChain.dir/brokerChain.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/brokerChain/brokerChain.cpp > CMakeFiles/brokerChain.dir/brokerChain.cpp.i

brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brokerChain.dir/brokerChain.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/brokerChain/brokerChain.cpp -o CMakeFiles/brokerChain.dir/brokerChain.cpp.s

# Object files for target brokerChain
brokerChain_OBJECTS = \
"CMakeFiles/brokerChain.dir/brokerChain.cpp.o"

# External object files for target brokerChain
brokerChain_EXTERNAL_OBJECTS =

brokerChain/brokerChain: brokerChain/CMakeFiles/brokerChain.dir/brokerChain.cpp.o
brokerChain/brokerChain: brokerChain/CMakeFiles/brokerChain.dir/build.make
brokerChain/brokerChain: brokerChain/CMakeFiles/brokerChain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable brokerChain"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/brokerChain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
brokerChain/CMakeFiles/brokerChain.dir/build: brokerChain/brokerChain

.PHONY : brokerChain/CMakeFiles/brokerChain.dir/build

brokerChain/CMakeFiles/brokerChain.dir/clean:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain && $(CMAKE_COMMAND) -P CMakeFiles/brokerChain.dir/cmake_clean.cmake
.PHONY : brokerChain/CMakeFiles/brokerChain.dir/clean

brokerChain/CMakeFiles/brokerChain.dir/depend:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michaldunda/Projects/ownProjects/C++/firstPattern /home/michaldunda/Projects/ownProjects/C++/firstPattern/brokerChain /home/michaldunda/Projects/ownProjects/C++/firstPattern/build /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/brokerChain/CMakeFiles/brokerChain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : brokerChain/CMakeFiles/brokerChain.dir/depend
