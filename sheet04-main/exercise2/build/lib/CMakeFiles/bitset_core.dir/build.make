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
CMAKE_SOURCE_DIR = /home/amir/CPP/sheet04/exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amir/CPP/sheet04/exercise2/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/bitset_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/bitset_core.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/bitset_core.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/bitset_core.dir/flags.make

lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o: lib/CMakeFiles/bitset_core.dir/flags.make
lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o: ../lib/BitSet.cpp
lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o: lib/CMakeFiles/bitset_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amir/CPP/sheet04/exercise2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o"
	cd /home/amir/CPP/sheet04/exercise2/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o -MF CMakeFiles/bitset_core.dir/BitSet.cpp.o.d -o CMakeFiles/bitset_core.dir/BitSet.cpp.o -c /home/amir/CPP/sheet04/exercise2/lib/BitSet.cpp

lib/CMakeFiles/bitset_core.dir/BitSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bitset_core.dir/BitSet.cpp.i"
	cd /home/amir/CPP/sheet04/exercise2/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amir/CPP/sheet04/exercise2/lib/BitSet.cpp > CMakeFiles/bitset_core.dir/BitSet.cpp.i

lib/CMakeFiles/bitset_core.dir/BitSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bitset_core.dir/BitSet.cpp.s"
	cd /home/amir/CPP/sheet04/exercise2/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amir/CPP/sheet04/exercise2/lib/BitSet.cpp -o CMakeFiles/bitset_core.dir/BitSet.cpp.s

# Object files for target bitset_core
bitset_core_OBJECTS = \
"CMakeFiles/bitset_core.dir/BitSet.cpp.o"

# External object files for target bitset_core
bitset_core_EXTERNAL_OBJECTS =

lib/libbitset_core.a: lib/CMakeFiles/bitset_core.dir/BitSet.cpp.o
lib/libbitset_core.a: lib/CMakeFiles/bitset_core.dir/build.make
lib/libbitset_core.a: lib/CMakeFiles/bitset_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amir/CPP/sheet04/exercise2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbitset_core.a"
	cd /home/amir/CPP/sheet04/exercise2/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/bitset_core.dir/cmake_clean_target.cmake
	cd /home/amir/CPP/sheet04/exercise2/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bitset_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/bitset_core.dir/build: lib/libbitset_core.a
.PHONY : lib/CMakeFiles/bitset_core.dir/build

lib/CMakeFiles/bitset_core.dir/clean:
	cd /home/amir/CPP/sheet04/exercise2/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/bitset_core.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/bitset_core.dir/clean

lib/CMakeFiles/bitset_core.dir/depend:
	cd /home/amir/CPP/sheet04/exercise2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amir/CPP/sheet04/exercise2 /home/amir/CPP/sheet04/exercise2/lib /home/amir/CPP/sheet04/exercise2/build /home/amir/CPP/sheet04/exercise2/build/lib /home/amir/CPP/sheet04/exercise2/build/lib/CMakeFiles/bitset_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/bitset_core.dir/depend
