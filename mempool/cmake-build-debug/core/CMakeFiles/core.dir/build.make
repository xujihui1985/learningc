# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/sean/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/sean/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/work/github.com/xujihui1985/learningc/mempool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug

# Include any dependencies generated for this target.
include core/CMakeFiles/core.dir/depend.make

# Include the progress variables for this target.
include core/CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/core.dir/flags.make

core/CMakeFiles/core.dir/pool.c.o: core/CMakeFiles/core.dir/flags.make
core/CMakeFiles/core.dir/pool.c.o: ../core/pool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object core/CMakeFiles/core.dir/pool.c.o"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/core.dir/pool.c.o   -c /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/pool.c

core/CMakeFiles/core.dir/pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/pool.c.i"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/pool.c > CMakeFiles/core.dir/pool.c.i

core/CMakeFiles/core.dir/pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/pool.c.s"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/pool.c -o CMakeFiles/core.dir/pool.c.s

core/CMakeFiles/core.dir/log.c.o: core/CMakeFiles/core.dir/flags.make
core/CMakeFiles/core.dir/log.c.o: ../core/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object core/CMakeFiles/core.dir/log.c.o"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/core.dir/log.c.o   -c /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/log.c

core/CMakeFiles/core.dir/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/log.c.i"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/log.c > CMakeFiles/core.dir/log.c.i

core/CMakeFiles/core.dir/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/log.c.s"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/log.c -o CMakeFiles/core.dir/log.c.s

core/CMakeFiles/core.dir/mempool.c.o: core/CMakeFiles/core.dir/flags.make
core/CMakeFiles/core.dir/mempool.c.o: ../core/mempool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object core/CMakeFiles/core.dir/mempool.c.o"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/core.dir/mempool.c.o   -c /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/mempool.c

core/CMakeFiles/core.dir/mempool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/mempool.c.i"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/mempool.c > CMakeFiles/core.dir/mempool.c.i

core/CMakeFiles/core.dir/mempool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/mempool.c.s"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean/work/github.com/xujihui1985/learningc/mempool/core/mempool.c -o CMakeFiles/core.dir/mempool.c.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/pool.c.o" \
"CMakeFiles/core.dir/log.c.o" \
"CMakeFiles/core.dir/mempool.c.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

core/libcore.a: core/CMakeFiles/core.dir/pool.c.o
core/libcore.a: core/CMakeFiles/core.dir/log.c.o
core/libcore.a: core/CMakeFiles/core.dir/mempool.c.o
core/libcore.a: core/CMakeFiles/core.dir/build.make
core/libcore.a: core/CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libcore.a"
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/core.dir/build: core/libcore.a

.PHONY : core/CMakeFiles/core.dir/build

core/CMakeFiles/core.dir/clean:
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/core.dir/clean

core/CMakeFiles/core.dir/depend:
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/work/github.com/xujihui1985/learningc/mempool /Users/sean/work/github.com/xujihui1985/learningc/mempool/core /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core /Users/sean/work/github.com/xujihui1985/learningc/mempool/cmake-build-debug/core/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/CMakeFiles/core.dir/depend

