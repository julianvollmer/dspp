# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra

# Include any dependencies generated for this target.
include CMakeFiles/Dijkstra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dijkstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dijkstra.dir/flags.make

CMakeFiles/Dijkstra.dir/oclDijkstra.o: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/oclDijkstra.o: oclDijkstra.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Dijkstra.dir/oclDijkstra.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Dijkstra.dir/oclDijkstra.o -c /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstra.cpp

CMakeFiles/Dijkstra.dir/oclDijkstra.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/oclDijkstra.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstra.cpp > CMakeFiles/Dijkstra.dir/oclDijkstra.i

CMakeFiles/Dijkstra.dir/oclDijkstra.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/oclDijkstra.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstra.cpp -o CMakeFiles/Dijkstra.dir/oclDijkstra.s

CMakeFiles/Dijkstra.dir/oclDijkstra.o.requires:
.PHONY : CMakeFiles/Dijkstra.dir/oclDijkstra.o.requires

CMakeFiles/Dijkstra.dir/oclDijkstra.o.provides: CMakeFiles/Dijkstra.dir/oclDijkstra.o.requires
	$(MAKE) -f CMakeFiles/Dijkstra.dir/build.make CMakeFiles/Dijkstra.dir/oclDijkstra.o.provides.build
.PHONY : CMakeFiles/Dijkstra.dir/oclDijkstra.o.provides

CMakeFiles/Dijkstra.dir/oclDijkstra.o.provides.build: CMakeFiles/Dijkstra.dir/oclDijkstra.o

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o: oclDijkstraKernel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o -c /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstraKernel.cpp

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/oclDijkstraKernel.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstraKernel.cpp > CMakeFiles/Dijkstra.dir/oclDijkstraKernel.i

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/oclDijkstraKernel.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/oclDijkstraKernel.cpp -o CMakeFiles/Dijkstra.dir/oclDijkstraKernel.s

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.requires:
.PHONY : CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.requires

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.provides: CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.requires
	$(MAKE) -f CMakeFiles/Dijkstra.dir/build.make CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.provides.build
.PHONY : CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.provides

CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.provides.build: CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o

# Object files for target Dijkstra
Dijkstra_OBJECTS = \
"CMakeFiles/Dijkstra.dir/oclDijkstra.o" \
"CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o"

# External object files for target Dijkstra
Dijkstra_EXTERNAL_OBJECTS =

Dijkstra: CMakeFiles/Dijkstra.dir/oclDijkstra.o
Dijkstra: CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o
Dijkstra: CMakeFiles/Dijkstra.dir/build.make
Dijkstra: /usr/lib64/libboost_program_options.so
Dijkstra: CMakeFiles/Dijkstra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Dijkstra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dijkstra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dijkstra.dir/build: Dijkstra
.PHONY : CMakeFiles/Dijkstra.dir/build

CMakeFiles/Dijkstra.dir/requires: CMakeFiles/Dijkstra.dir/oclDijkstra.o.requires
CMakeFiles/Dijkstra.dir/requires: CMakeFiles/Dijkstra.dir/oclDijkstraKernel.o.requires
.PHONY : CMakeFiles/Dijkstra.dir/requires

CMakeFiles/Dijkstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dijkstra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dijkstra.dir/clean

CMakeFiles/Dijkstra.dir/depend:
	cd /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra /home/sodoku/Projekte/htw/ParallelPrograming/openCLdijkstra/CMakeFiles/Dijkstra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dijkstra.dir/depend

