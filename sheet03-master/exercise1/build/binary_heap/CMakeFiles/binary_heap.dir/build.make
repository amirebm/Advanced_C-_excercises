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
CMAKE_SOURCE_DIR = /home/amir/CPP/sheet03/exercise1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amir/CPP/sheet03/exercise1/build

# Include any dependencies generated for this target.
include binary_heap/CMakeFiles/binary_heap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include binary_heap/CMakeFiles/binary_heap.dir/compiler_depend.make

# Include the progress variables for this target.
include binary_heap/CMakeFiles/binary_heap.dir/progress.make

# Include the compile flags for this target's objects.
include binary_heap/CMakeFiles/binary_heap.dir/flags.make

binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o: binary_heap/CMakeFiles/binary_heap.dir/flags.make
binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o: ../binary_heap/main.cpp
binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o: binary_heap/CMakeFiles/binary_heap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amir/CPP/sheet03/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o"
	cd /home/amir/CPP/sheet03/exercise1/build/binary_heap && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o -MF CMakeFiles/binary_heap.dir/main.cpp.o.d -o CMakeFiles/binary_heap.dir/main.cpp.o -c /home/amir/CPP/sheet03/exercise1/binary_heap/main.cpp

binary_heap/CMakeFiles/binary_heap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_heap.dir/main.cpp.i"
	cd /home/amir/CPP/sheet03/exercise1/build/binary_heap && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amir/CPP/sheet03/exercise1/binary_heap/main.cpp > CMakeFiles/binary_heap.dir/main.cpp.i

binary_heap/CMakeFiles/binary_heap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_heap.dir/main.cpp.s"
	cd /home/amir/CPP/sheet03/exercise1/build/binary_heap && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amir/CPP/sheet03/exercise1/binary_heap/main.cpp -o CMakeFiles/binary_heap.dir/main.cpp.s

# Object files for target binary_heap
binary_heap_OBJECTS = \
"CMakeFiles/binary_heap.dir/main.cpp.o"

# External object files for target binary_heap
binary_heap_EXTERNAL_OBJECTS =

binary_heap/binary_heap: binary_heap/CMakeFiles/binary_heap.dir/main.cpp.o
binary_heap/binary_heap: binary_heap/CMakeFiles/binary_heap.dir/build.make
binary_heap/binary_heap: lib/libbinary_heap_core.a
binary_heap/binary_heap: binary_heap/CMakeFiles/binary_heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amir/CPP/sheet03/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_heap"
	cd /home/amir/CPP/sheet03/exercise1/build/binary_heap && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_heap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
binary_heap/CMakeFiles/binary_heap.dir/build: binary_heap/binary_heap
.PHONY : binary_heap/CMakeFiles/binary_heap.dir/build

binary_heap/CMakeFiles/binary_heap.dir/clean:
	cd /home/amir/CPP/sheet03/exercise1/build/binary_heap && $(CMAKE_COMMAND) -P CMakeFiles/binary_heap.dir/cmake_clean.cmake
.PHONY : binary_heap/CMakeFiles/binary_heap.dir/clean

binary_heap/CMakeFiles/binary_heap.dir/depend:
	cd /home/amir/CPP/sheet03/exercise1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amir/CPP/sheet03/exercise1 /home/amir/CPP/sheet03/exercise1/binary_heap /home/amir/CPP/sheet03/exercise1/build /home/amir/CPP/sheet03/exercise1/build/binary_heap /home/amir/CPP/sheet03/exercise1/build/binary_heap/CMakeFiles/binary_heap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : binary_heap/CMakeFiles/binary_heap.dir/depend
