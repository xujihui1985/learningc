# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build

# Include any dependencies generated for this target.
include CMakeFiles/sequential-server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sequential-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sequential-server.dir/flags.make

CMakeFiles/sequential-server.dir/sequential-server.c.o: CMakeFiles/sequential-server.dir/flags.make
CMakeFiles/sequential-server.dir/sequential-server.c.o: ../sequential-server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sequential-server.dir/sequential-server.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sequential-server.dir/sequential-server.c.o   -c /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/sequential-server.c

CMakeFiles/sequential-server.dir/sequential-server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sequential-server.dir/sequential-server.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/sequential-server.c > CMakeFiles/sequential-server.dir/sequential-server.c.i

CMakeFiles/sequential-server.dir/sequential-server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sequential-server.dir/sequential-server.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/sequential-server.c -o CMakeFiles/sequential-server.dir/sequential-server.c.s

# Object files for target sequential-server
sequential__server_OBJECTS = \
"CMakeFiles/sequential-server.dir/sequential-server.c.o"

# External object files for target sequential-server
sequential__server_EXTERNAL_OBJECTS =

sequential-server: CMakeFiles/sequential-server.dir/sequential-server.c.o
sequential-server: CMakeFiles/sequential-server.dir/build.make
sequential-server: libutils.a
sequential-server: CMakeFiles/sequential-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sequential-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sequential-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sequential-server.dir/build: sequential-server

.PHONY : CMakeFiles/sequential-server.dir/build

CMakeFiles/sequential-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sequential-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sequential-server.dir/clean

CMakeFiles/sequential-server.dir/depend:
	cd /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build /Users/sean/work/github.com/xujihui1985/learningc/async-socket-server/sequential/build/CMakeFiles/sequential-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sequential-server.dir/depend

