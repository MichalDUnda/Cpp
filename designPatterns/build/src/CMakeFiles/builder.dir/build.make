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
include src/CMakeFiles/builder.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/builder.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/builder.dir/flags.make

src/CMakeFiles/builder.dir/Person.cpp.o: src/CMakeFiles/builder.dir/flags.make
src/CMakeFiles/builder.dir/Person.cpp.o: ../src/Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/builder.dir/Person.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/builder.dir/Person.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/Person.cpp

src/CMakeFiles/builder.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/builder.dir/Person.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/Person.cpp > CMakeFiles/builder.dir/Person.cpp.i

src/CMakeFiles/builder.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/builder.dir/Person.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/Person.cpp -o CMakeFiles/builder.dir/Person.cpp.s

src/CMakeFiles/builder.dir/PersonBuilder.cpp.o: src/CMakeFiles/builder.dir/flags.make
src/CMakeFiles/builder.dir/PersonBuilder.cpp.o: ../src/PersonBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/builder.dir/PersonBuilder.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/builder.dir/PersonBuilder.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/PersonBuilder.cpp

src/CMakeFiles/builder.dir/PersonBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/builder.dir/PersonBuilder.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/PersonBuilder.cpp > CMakeFiles/builder.dir/PersonBuilder.cpp.i

src/CMakeFiles/builder.dir/PersonBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/builder.dir/PersonBuilder.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/PersonBuilder.cpp -o CMakeFiles/builder.dir/PersonBuilder.cpp.s

src/CMakeFiles/builder.dir/main.cpp.o: src/CMakeFiles/builder.dir/flags.make
src/CMakeFiles/builder.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/builder.dir/main.cpp.o"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/builder.dir/main.cpp.o -c /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/main.cpp

src/CMakeFiles/builder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/builder.dir/main.cpp.i"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/main.cpp > CMakeFiles/builder.dir/main.cpp.i

src/CMakeFiles/builder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/builder.dir/main.cpp.s"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michaldunda/Projects/ownProjects/C++/firstPattern/src/main.cpp -o CMakeFiles/builder.dir/main.cpp.s

# Object files for target builder
builder_OBJECTS = \
"CMakeFiles/builder.dir/Person.cpp.o" \
"CMakeFiles/builder.dir/PersonBuilder.cpp.o" \
"CMakeFiles/builder.dir/main.cpp.o"

# External object files for target builder
builder_EXTERNAL_OBJECTS =

src/builder: src/CMakeFiles/builder.dir/Person.cpp.o
src/builder: src/CMakeFiles/builder.dir/PersonBuilder.cpp.o
src/builder: src/CMakeFiles/builder.dir/main.cpp.o
src/builder: src/CMakeFiles/builder.dir/build.make
src/builder: src/CMakeFiles/builder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michaldunda/Projects/ownProjects/C++/firstPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable builder"
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/builder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/builder.dir/build: src/builder

.PHONY : src/CMakeFiles/builder.dir/build

src/CMakeFiles/builder.dir/clean:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src && $(CMAKE_COMMAND) -P CMakeFiles/builder.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/builder.dir/clean

src/CMakeFiles/builder.dir/depend:
	cd /home/michaldunda/Projects/ownProjects/C++/firstPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michaldunda/Projects/ownProjects/C++/firstPattern /home/michaldunda/Projects/ownProjects/C++/firstPattern/src /home/michaldunda/Projects/ownProjects/C++/firstPattern/build /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src /home/michaldunda/Projects/ownProjects/C++/firstPattern/build/src/CMakeFiles/builder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/builder.dir/depend

