# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/cristina/Desktop/C++ folder game/2D-game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/cristina/Desktop/C++ folder game/2D-game/build"

# Include any dependencies generated for this target.
include CMakeFiles/2D_game_assignment.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2D_game_assignment.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2D_game_assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2D_game_assignment.dir/flags.make

CMakeFiles/2D_game_assignment.dir/src/main.cpp.o: CMakeFiles/2D_game_assignment.dir/flags.make
CMakeFiles/2D_game_assignment.dir/src/main.cpp.o: /Users/cristina/Desktop/C++\ folder\ game/2D-game/src/main.cpp
CMakeFiles/2D_game_assignment.dir/src/main.cpp.o: CMakeFiles/2D_game_assignment.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/cristina/Desktop/C++ folder game/2D-game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2D_game_assignment.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2D_game_assignment.dir/src/main.cpp.o -MF CMakeFiles/2D_game_assignment.dir/src/main.cpp.o.d -o CMakeFiles/2D_game_assignment.dir/src/main.cpp.o -c "/Users/cristina/Desktop/C++ folder game/2D-game/src/main.cpp"

CMakeFiles/2D_game_assignment.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/2D_game_assignment.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/cristina/Desktop/C++ folder game/2D-game/src/main.cpp" > CMakeFiles/2D_game_assignment.dir/src/main.cpp.i

CMakeFiles/2D_game_assignment.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/2D_game_assignment.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/cristina/Desktop/C++ folder game/2D-game/src/main.cpp" -o CMakeFiles/2D_game_assignment.dir/src/main.cpp.s

CMakeFiles/2D_game_assignment.dir/src/game.cpp.o: CMakeFiles/2D_game_assignment.dir/flags.make
CMakeFiles/2D_game_assignment.dir/src/game.cpp.o: /Users/cristina/Desktop/C++\ folder\ game/2D-game/src/game.cpp
CMakeFiles/2D_game_assignment.dir/src/game.cpp.o: CMakeFiles/2D_game_assignment.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/cristina/Desktop/C++ folder game/2D-game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2D_game_assignment.dir/src/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2D_game_assignment.dir/src/game.cpp.o -MF CMakeFiles/2D_game_assignment.dir/src/game.cpp.o.d -o CMakeFiles/2D_game_assignment.dir/src/game.cpp.o -c "/Users/cristina/Desktop/C++ folder game/2D-game/src/game.cpp"

CMakeFiles/2D_game_assignment.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/2D_game_assignment.dir/src/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/cristina/Desktop/C++ folder game/2D-game/src/game.cpp" > CMakeFiles/2D_game_assignment.dir/src/game.cpp.i

CMakeFiles/2D_game_assignment.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/2D_game_assignment.dir/src/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/cristina/Desktop/C++ folder game/2D-game/src/game.cpp" -o CMakeFiles/2D_game_assignment.dir/src/game.cpp.s

# Object files for target 2D_game_assignment
2D_game_assignment_OBJECTS = \
"CMakeFiles/2D_game_assignment.dir/src/main.cpp.o" \
"CMakeFiles/2D_game_assignment.dir/src/game.cpp.o"

# External object files for target 2D_game_assignment
2D_game_assignment_EXTERNAL_OBJECTS =

2D_game_assignment: CMakeFiles/2D_game_assignment.dir/src/main.cpp.o
2D_game_assignment: CMakeFiles/2D_game_assignment.dir/src/game.cpp.o
2D_game_assignment: CMakeFiles/2D_game_assignment.dir/build.make
2D_game_assignment: CMakeFiles/2D_game_assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/cristina/Desktop/C++ folder game/2D-game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 2D_game_assignment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2D_game_assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2D_game_assignment.dir/build: 2D_game_assignment
.PHONY : CMakeFiles/2D_game_assignment.dir/build

CMakeFiles/2D_game_assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2D_game_assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2D_game_assignment.dir/clean

CMakeFiles/2D_game_assignment.dir/depend:
	cd "/Users/cristina/Desktop/C++ folder game/2D-game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/cristina/Desktop/C++ folder game/2D-game" "/Users/cristina/Desktop/C++ folder game/2D-game" "/Users/cristina/Desktop/C++ folder game/2D-game/build" "/Users/cristina/Desktop/C++ folder game/2D-game/build" "/Users/cristina/Desktop/C++ folder game/2D-game/build/CMakeFiles/2D_game_assignment.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/2D_game_assignment.dir/depend
