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
CMAKE_SOURCE_DIR = /home/odin/poose_markt/p3_mwe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odin/poose_markt/p3_mwe/build

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/examples/demo.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/examples/demo.cpp.o: ../examples/demo.cpp
CMakeFiles/demo.dir/examples/demo.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/odin/poose_markt/p3_mwe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/examples/demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/examples/demo.cpp.o -MF CMakeFiles/demo.dir/examples/demo.cpp.o.d -o CMakeFiles/demo.dir/examples/demo.cpp.o -c /home/odin/poose_markt/p3_mwe/examples/demo.cpp

CMakeFiles/demo.dir/examples/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/examples/demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/odin/poose_markt/p3_mwe/examples/demo.cpp > CMakeFiles/demo.dir/examples/demo.cpp.i

CMakeFiles/demo.dir/examples/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/examples/demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/odin/poose_markt/p3_mwe/examples/demo.cpp -o CMakeFiles/demo.dir/examples/demo.cpp.s

CMakeFiles/demo.dir/src/Angebot.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Angebot.cpp.o: ../src/Angebot.cpp
CMakeFiles/demo.dir/src/Angebot.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/odin/poose_markt/p3_mwe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/src/Angebot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/src/Angebot.cpp.o -MF CMakeFiles/demo.dir/src/Angebot.cpp.o.d -o CMakeFiles/demo.dir/src/Angebot.cpp.o -c /home/odin/poose_markt/p3_mwe/src/Angebot.cpp

CMakeFiles/demo.dir/src/Angebot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Angebot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/odin/poose_markt/p3_mwe/src/Angebot.cpp > CMakeFiles/demo.dir/src/Angebot.cpp.i

CMakeFiles/demo.dir/src/Angebot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Angebot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/odin/poose_markt/p3_mwe/src/Angebot.cpp -o CMakeFiles/demo.dir/src/Angebot.cpp.s

CMakeFiles/demo.dir/src/Markt.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Markt.cpp.o: ../src/Markt.cpp
CMakeFiles/demo.dir/src/Markt.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/odin/poose_markt/p3_mwe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo.dir/src/Markt.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/src/Markt.cpp.o -MF CMakeFiles/demo.dir/src/Markt.cpp.o.d -o CMakeFiles/demo.dir/src/Markt.cpp.o -c /home/odin/poose_markt/p3_mwe/src/Markt.cpp

CMakeFiles/demo.dir/src/Markt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Markt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/odin/poose_markt/p3_mwe/src/Markt.cpp > CMakeFiles/demo.dir/src/Markt.cpp.i

CMakeFiles/demo.dir/src/Markt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Markt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/odin/poose_markt/p3_mwe/src/Markt.cpp -o CMakeFiles/demo.dir/src/Markt.cpp.s

CMakeFiles/demo.dir/src/Nutzer.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Nutzer.cpp.o: ../src/Nutzer.cpp
CMakeFiles/demo.dir/src/Nutzer.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/odin/poose_markt/p3_mwe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/demo.dir/src/Nutzer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/src/Nutzer.cpp.o -MF CMakeFiles/demo.dir/src/Nutzer.cpp.o.d -o CMakeFiles/demo.dir/src/Nutzer.cpp.o -c /home/odin/poose_markt/p3_mwe/src/Nutzer.cpp

CMakeFiles/demo.dir/src/Nutzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Nutzer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/odin/poose_markt/p3_mwe/src/Nutzer.cpp > CMakeFiles/demo.dir/src/Nutzer.cpp.i

CMakeFiles/demo.dir/src/Nutzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Nutzer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/odin/poose_markt/p3_mwe/src/Nutzer.cpp -o CMakeFiles/demo.dir/src/Nutzer.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/examples/demo.cpp.o" \
"CMakeFiles/demo.dir/src/Angebot.cpp.o" \
"CMakeFiles/demo.dir/src/Markt.cpp.o" \
"CMakeFiles/demo.dir/src/Nutzer.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/examples/demo.cpp.o
demo: CMakeFiles/demo.dir/src/Angebot.cpp.o
demo: CMakeFiles/demo.dir/src/Markt.cpp.o
demo: CMakeFiles/demo.dir/src/Nutzer.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/odin/poose_markt/p3_mwe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo
.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/odin/poose_markt/p3_mwe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odin/poose_markt/p3_mwe /home/odin/poose_markt/p3_mwe /home/odin/poose_markt/p3_mwe/build /home/odin/poose_markt/p3_mwe/build /home/odin/poose_markt/p3_mwe/build/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

