# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/work/github.com/xujihui1985/learningc/mempool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/work/github.com/xujihui1985/learningc/mempool/build

# Include any dependencies generated for this target.
include CMakeFiles/mempool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mempool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mempool.dir/flags.make

CMakeFiles/mempool.dir/main.c.o: CMakeFiles/mempool.dir/flags.make
CMakeFiles/mempool.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mempool.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mempool.dir/main.c.o   -c /Users/sean/work/github.com/xujihui1985/learningc/mempool/main.c

CMakeFiles/mempool.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mempool.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean/work/github.com/xujihui1985/learningc/mempool/main.c > CMakeFiles/mempool.dir/main.c.i

CMakeFiles/mempool.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mempool.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean/work/github.com/xujihui1985/learningc/mempool/main.c -o CMakeFiles/mempool.dir/main.c.s

# Object files for target mempool
mempool_OBJECTS = \
"CMakeFiles/mempool.dir/main.c.o"

# External object files for target mempool
mempool_EXTERNAL_OBJECTS =

mempool: CMakeFiles/mempool.dir/main.c.o
mempool: CMakeFiles/mempool.dir/build.make
mempool: core/libcore.a
mempool: CMakeFiles/mempool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean/work/github.com/xujihui1985/learningc/mempool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mempool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mempool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mempool.dir/build: mempool

.PHONY : CMakeFiles/mempool.dir/build

CMakeFiles/mempool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mempool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mempool.dir/clean

CMakeFiles/mempool.dir/depend:
	cd /Users/sean/work/github.com/xujihui1985/learningc/mempool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/work/github.com/xujihui1985/learningc/mempool /Users/sean/work/github.com/xujihui1985/learningc/mempool /Users/sean/work/github.com/xujihui1985/learningc/mempool/build /Users/sean/work/github.com/xujihui1985/learningc/mempool/build /Users/sean/work/github.com/xujihui1985/learningc/mempool/build/CMakeFiles/mempool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mempool.dir/depend
