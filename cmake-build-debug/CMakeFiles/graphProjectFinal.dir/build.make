# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\graphProjectFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\graphProjectFinal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graphProjectFinal.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/graphProjectFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphProjectFinal.dir/flags.make

CMakeFiles/graphProjectFinal.dir/main.cpp.obj: CMakeFiles/graphProjectFinal.dir/flags.make
CMakeFiles/graphProjectFinal.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\graphProjectFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphProjectFinal.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\graphProjectFinal.dir\main.cpp.obj -c D:\graphProjectFinal\main.cpp

CMakeFiles/graphProjectFinal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProjectFinal.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\graphProjectFinal\main.cpp > CMakeFiles\graphProjectFinal.dir\main.cpp.i

CMakeFiles/graphProjectFinal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProjectFinal.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\graphProjectFinal\main.cpp -o CMakeFiles\graphProjectFinal.dir\main.cpp.s

CMakeFiles/graphProjectFinal.dir/Graph.cpp.obj: CMakeFiles/graphProjectFinal.dir/flags.make
CMakeFiles/graphProjectFinal.dir/Graph.cpp.obj: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\graphProjectFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphProjectFinal.dir/Graph.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\graphProjectFinal.dir\Graph.cpp.obj -c D:\graphProjectFinal\Graph.cpp

CMakeFiles/graphProjectFinal.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphProjectFinal.dir/Graph.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\graphProjectFinal\Graph.cpp > CMakeFiles\graphProjectFinal.dir\Graph.cpp.i

CMakeFiles/graphProjectFinal.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphProjectFinal.dir/Graph.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\graphProjectFinal\Graph.cpp -o CMakeFiles\graphProjectFinal.dir\Graph.cpp.s

# Object files for target graphProjectFinal
graphProjectFinal_OBJECTS = \
"CMakeFiles/graphProjectFinal.dir/main.cpp.obj" \
"CMakeFiles/graphProjectFinal.dir/Graph.cpp.obj"

# External object files for target graphProjectFinal
graphProjectFinal_EXTERNAL_OBJECTS =

graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/main.cpp.obj
graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/Graph.cpp.obj
graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/build.make
graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/linklibs.rsp
graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/objects1.rsp
graphProjectFinal.exe: CMakeFiles/graphProjectFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\graphProjectFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphProjectFinal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graphProjectFinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphProjectFinal.dir/build: graphProjectFinal.exe
.PHONY : CMakeFiles/graphProjectFinal.dir/build

CMakeFiles/graphProjectFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graphProjectFinal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graphProjectFinal.dir/clean

CMakeFiles/graphProjectFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\graphProjectFinal D:\graphProjectFinal D:\graphProjectFinal\cmake-build-debug D:\graphProjectFinal\cmake-build-debug D:\graphProjectFinal\cmake-build-debug\CMakeFiles\graphProjectFinal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphProjectFinal.dir/depend

