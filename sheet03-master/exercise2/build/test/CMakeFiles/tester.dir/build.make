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
CMAKE_SOURCE_DIR = /home/amir/CPP/sheet03/exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amir/CPP/sheet03/exercise2/build

# Include any dependencies generated for this target.
include test/CMakeFiles/tester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/tester.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tester.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tester.dir/flags.make

test/CMakeFiles/tester.dir/Tester.cpp.o: test/CMakeFiles/tester.dir/flags.make
test/CMakeFiles/tester.dir/Tester.cpp.o: ../test/Tester.cpp
test/CMakeFiles/tester.dir/Tester.cpp.o: test/CMakeFiles/tester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amir/CPP/sheet03/exercise2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/tester.dir/Tester.cpp.o"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tester.dir/Tester.cpp.o -MF CMakeFiles/tester.dir/Tester.cpp.o.d -o CMakeFiles/tester.dir/Tester.cpp.o -c /home/amir/CPP/sheet03/exercise2/test/Tester.cpp

test/CMakeFiles/tester.dir/Tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tester.dir/Tester.cpp.i"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amir/CPP/sheet03/exercise2/test/Tester.cpp > CMakeFiles/tester.dir/Tester.cpp.i

test/CMakeFiles/tester.dir/Tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tester.dir/Tester.cpp.s"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amir/CPP/sheet03/exercise2/test/Tester.cpp -o CMakeFiles/tester.dir/Tester.cpp.s

test/CMakeFiles/tester.dir/TestSortPointers.cpp.o: test/CMakeFiles/tester.dir/flags.make
test/CMakeFiles/tester.dir/TestSortPointers.cpp.o: ../test/TestSortPointers.cpp
test/CMakeFiles/tester.dir/TestSortPointers.cpp.o: test/CMakeFiles/tester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amir/CPP/sheet03/exercise2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/tester.dir/TestSortPointers.cpp.o"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tester.dir/TestSortPointers.cpp.o -MF CMakeFiles/tester.dir/TestSortPointers.cpp.o.d -o CMakeFiles/tester.dir/TestSortPointers.cpp.o -c /home/amir/CPP/sheet03/exercise2/test/TestSortPointers.cpp

test/CMakeFiles/tester.dir/TestSortPointers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tester.dir/TestSortPointers.cpp.i"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amir/CPP/sheet03/exercise2/test/TestSortPointers.cpp > CMakeFiles/tester.dir/TestSortPointers.cpp.i

test/CMakeFiles/tester.dir/TestSortPointers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tester.dir/TestSortPointers.cpp.s"
	cd /home/amir/CPP/sheet03/exercise2/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amir/CPP/sheet03/exercise2/test/TestSortPointers.cpp -o CMakeFiles/tester.dir/TestSortPointers.cpp.s

# Object files for target tester
tester_OBJECTS = \
"CMakeFiles/tester.dir/Tester.cpp.o" \
"CMakeFiles/tester.dir/TestSortPointers.cpp.o"

# External object files for target tester
tester_EXTERNAL_OBJECTS =

test/tester: test/CMakeFiles/tester.dir/Tester.cpp.o
test/tester: test/CMakeFiles/tester.dir/TestSortPointers.cpp.o
test/tester: test/CMakeFiles/tester.dir/build.make
test/tester: lib/libsort_pointers_core.a
test/tester: /usr/lib/x86_64-linux-gnu/libgtest.a
test/tester: test/CMakeFiles/tester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amir/CPP/sheet03/exercise2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tester"
	cd /home/amir/CPP/sheet03/exercise2/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/tester.dir/build: test/tester
.PHONY : test/CMakeFiles/tester.dir/build

test/CMakeFiles/tester.dir/clean:
	cd /home/amir/CPP/sheet03/exercise2/build/test && $(CMAKE_COMMAND) -P CMakeFiles/tester.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/tester.dir/clean

test/CMakeFiles/tester.dir/depend:
	cd /home/amir/CPP/sheet03/exercise2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amir/CPP/sheet03/exercise2 /home/amir/CPP/sheet03/exercise2/test /home/amir/CPP/sheet03/exercise2/build /home/amir/CPP/sheet03/exercise2/build/test /home/amir/CPP/sheet03/exercise2/build/test/CMakeFiles/tester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tester.dir/depend

