# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /private/var/folders/3_/9d5vfl4x34v6_ss_xb52knt40000gn/T/AppTranslocation/EDDA0A2C-250A-4A5D-9DCF-4244CEC15A7D/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/3_/9d5vfl4x34v6_ss_xb52knt40000gn/T/AppTranslocation/EDDA0A2C-250A-4A5D-9DCF-4244CEC15A7D/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiahuatang/CLionProjects/NetflixRepo2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NetflixRepo2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/NetflixRepo2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NetflixRepo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NetflixRepo2.dir/flags.make

CMakeFiles/NetflixRepo2.dir/main.cpp.o: CMakeFiles/NetflixRepo2.dir/flags.make
CMakeFiles/NetflixRepo2.dir/main.cpp.o: /Users/jiahuatang/CLionProjects/NetflixRepo2/main.cpp
CMakeFiles/NetflixRepo2.dir/main.cpp.o: CMakeFiles/NetflixRepo2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NetflixRepo2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NetflixRepo2.dir/main.cpp.o -MF CMakeFiles/NetflixRepo2.dir/main.cpp.o.d -o CMakeFiles/NetflixRepo2.dir/main.cpp.o -c /Users/jiahuatang/CLionProjects/NetflixRepo2/main.cpp

CMakeFiles/NetflixRepo2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetflixRepo2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiahuatang/CLionProjects/NetflixRepo2/main.cpp > CMakeFiles/NetflixRepo2.dir/main.cpp.i

CMakeFiles/NetflixRepo2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetflixRepo2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiahuatang/CLionProjects/NetflixRepo2/main.cpp -o CMakeFiles/NetflixRepo2.dir/main.cpp.s

# Object files for target NetflixRepo2
NetflixRepo2_OBJECTS = \
"CMakeFiles/NetflixRepo2.dir/main.cpp.o"

# External object files for target NetflixRepo2
NetflixRepo2_EXTERNAL_OBJECTS =

NetflixRepo2: CMakeFiles/NetflixRepo2.dir/main.cpp.o
NetflixRepo2: CMakeFiles/NetflixRepo2.dir/build.make
NetflixRepo2: CMakeFiles/NetflixRepo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NetflixRepo2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NetflixRepo2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NetflixRepo2.dir/build: NetflixRepo2
.PHONY : CMakeFiles/NetflixRepo2.dir/build

CMakeFiles/NetflixRepo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NetflixRepo2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NetflixRepo2.dir/clean

CMakeFiles/NetflixRepo2.dir/depend:
	cd /Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiahuatang/CLionProjects/NetflixRepo2 /Users/jiahuatang/CLionProjects/NetflixRepo2 /Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug /Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug /Users/jiahuatang/CLionProjects/NetflixRepo2/cmake-build-debug/CMakeFiles/NetflixRepo2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NetflixRepo2.dir/depend
