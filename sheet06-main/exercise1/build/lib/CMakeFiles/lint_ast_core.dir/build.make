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
CMAKE_SOURCE_DIR = /home/amir/simin/sheet06/exercise1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amir/simin/sheet06/exercise1/build

# Utility rule file for lint_ast_core.

# Include any custom commands dependencies for this target.
include lib/CMakeFiles/lint_ast_core.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/lint_ast_core.dir/progress.make

lib/CMakeFiles/lint_ast_core:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amir/simin/sheet06/exercise1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running lint_ast_core"
	cd /home/amir/simin/sheet06/exercise1/build/lib && /usr/bin/cmake -E chdir /home/amir/simin/sheet06/exercise1/lib /usr/bin/clang-tidy -quiet -p=/home/amir/simin/sheet06/exercise1/build/lib AST.cpp EvaluationContext.cpp PrintVisitor.cpp

lint_ast_core: lib/CMakeFiles/lint_ast_core
lint_ast_core: lib/CMakeFiles/lint_ast_core.dir/build.make
.PHONY : lint_ast_core

# Rule to build all files generated by this target.
lib/CMakeFiles/lint_ast_core.dir/build: lint_ast_core
.PHONY : lib/CMakeFiles/lint_ast_core.dir/build

lib/CMakeFiles/lint_ast_core.dir/clean:
	cd /home/amir/simin/sheet06/exercise1/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/lint_ast_core.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/lint_ast_core.dir/clean

lib/CMakeFiles/lint_ast_core.dir/depend:
	cd /home/amir/simin/sheet06/exercise1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amir/simin/sheet06/exercise1 /home/amir/simin/sheet06/exercise1/lib /home/amir/simin/sheet06/exercise1/build /home/amir/simin/sheet06/exercise1/build/lib /home/amir/simin/sheet06/exercise1/build/lib/CMakeFiles/lint_ast_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/lint_ast_core.dir/depend
