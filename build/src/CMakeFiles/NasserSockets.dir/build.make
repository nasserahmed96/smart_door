# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nasser/myproject/Smart_Door

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nasser/myproject/Smart_Door/build

# Include any dependencies generated for this target.
include src/CMakeFiles/NasserSockets.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/NasserSockets.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/NasserSockets.dir/flags.make

src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o: src/CMakeFiles/NasserSockets.dir/flags.make
src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o: ../src/c_sockets_nasser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nasser/myproject/Smart_Door/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o"
	cd /home/nasser/myproject/Smart_Door/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o   -c /home/nasser/myproject/Smart_Door/src/c_sockets_nasser.c

src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.i"
	cd /home/nasser/myproject/Smart_Door/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nasser/myproject/Smart_Door/src/c_sockets_nasser.c > CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.i

src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.s"
	cd /home/nasser/myproject/Smart_Door/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nasser/myproject/Smart_Door/src/c_sockets_nasser.c -o CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.s

# Object files for target NasserSockets
NasserSockets_OBJECTS = \
"CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o"

# External object files for target NasserSockets
NasserSockets_EXTERNAL_OBJECTS =

src/libNasserSockets.a: src/CMakeFiles/NasserSockets.dir/c_sockets_nasser.c.o
src/libNasserSockets.a: src/CMakeFiles/NasserSockets.dir/build.make
src/libNasserSockets.a: src/CMakeFiles/NasserSockets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nasser/myproject/Smart_Door/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libNasserSockets.a"
	cd /home/nasser/myproject/Smart_Door/build/src && $(CMAKE_COMMAND) -P CMakeFiles/NasserSockets.dir/cmake_clean_target.cmake
	cd /home/nasser/myproject/Smart_Door/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NasserSockets.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/NasserSockets.dir/build: src/libNasserSockets.a

.PHONY : src/CMakeFiles/NasserSockets.dir/build

src/CMakeFiles/NasserSockets.dir/clean:
	cd /home/nasser/myproject/Smart_Door/build/src && $(CMAKE_COMMAND) -P CMakeFiles/NasserSockets.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/NasserSockets.dir/clean

src/CMakeFiles/NasserSockets.dir/depend:
	cd /home/nasser/myproject/Smart_Door/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nasser/myproject/Smart_Door /home/nasser/myproject/Smart_Door/src /home/nasser/myproject/Smart_Door/build /home/nasser/myproject/Smart_Door/build/src /home/nasser/myproject/Smart_Door/build/src/CMakeFiles/NasserSockets.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/NasserSockets.dir/depend

