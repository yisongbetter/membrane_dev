# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "/Users/LiYisong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/LiYisong/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/LiYisong/CLionProjects/lsd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/LiYisong/CLionProjects/lsd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lsd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lsd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lsd.dir/flags.make

CMakeFiles/lsd.dir/main.cpp.o: CMakeFiles/lsd.dir/flags.make
CMakeFiles/lsd.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/LiYisong/CLionProjects/lsd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lsd.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsd.dir/main.cpp.o -c /Users/LiYisong/CLionProjects/lsd/main.cpp

CMakeFiles/lsd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsd.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/LiYisong/CLionProjects/lsd/main.cpp > CMakeFiles/lsd.dir/main.cpp.i

CMakeFiles/lsd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsd.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/LiYisong/CLionProjects/lsd/main.cpp -o CMakeFiles/lsd.dir/main.cpp.s

CMakeFiles/lsd.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lsd.dir/main.cpp.o.requires

CMakeFiles/lsd.dir/main.cpp.o.provides: CMakeFiles/lsd.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lsd.dir/build.make CMakeFiles/lsd.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lsd.dir/main.cpp.o.provides

CMakeFiles/lsd.dir/main.cpp.o.provides.build: CMakeFiles/lsd.dir/main.cpp.o


# Object files for target lsd
lsd_OBJECTS = \
"CMakeFiles/lsd.dir/main.cpp.o"

# External object files for target lsd
lsd_EXTERNAL_OBJECTS =

lsd: CMakeFiles/lsd.dir/main.cpp.o
lsd: CMakeFiles/lsd.dir/build.make
lsd: CMakeFiles/lsd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/LiYisong/CLionProjects/lsd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lsd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lsd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lsd.dir/build: lsd

.PHONY : CMakeFiles/lsd.dir/build

CMakeFiles/lsd.dir/requires: CMakeFiles/lsd.dir/main.cpp.o.requires

.PHONY : CMakeFiles/lsd.dir/requires

CMakeFiles/lsd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lsd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lsd.dir/clean

CMakeFiles/lsd.dir/depend:
	cd /Users/LiYisong/CLionProjects/lsd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/LiYisong/CLionProjects/lsd /Users/LiYisong/CLionProjects/lsd /Users/LiYisong/CLionProjects/lsd/cmake-build-debug /Users/LiYisong/CLionProjects/lsd/cmake-build-debug /Users/LiYisong/CLionProjects/lsd/cmake-build-debug/CMakeFiles/lsd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lsd.dir/depend

