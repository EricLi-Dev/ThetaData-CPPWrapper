# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ericli/Documents/ThetaData/CPP_API_Wrapper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ericli/Documents/ThetaData/CPP_API_Wrapper

# Include any dependencies generated for this target.
include CMakeFiles/thetaData_cpp_wrapper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thetaData_cpp_wrapper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thetaData_cpp_wrapper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thetaData_cpp_wrapper.dir/flags.make

CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o: CMakeFiles/thetaData_cpp_wrapper.dir/flags.make
CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o: main.cpp
CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o: CMakeFiles/thetaData_cpp_wrapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o -MF CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o.d -o CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o -c /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/main.cpp

CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/main.cpp > CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.i

CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/main.cpp -o CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.s

CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o: CMakeFiles/thetaData_cpp_wrapper.dir/flags.make
CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o: client.cpp
CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o: CMakeFiles/thetaData_cpp_wrapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o -MF CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o.d -o CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o -c /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/client.cpp

CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/client.cpp > CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.i

CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/client.cpp -o CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.s

# Object files for target thetaData_cpp_wrapper
thetaData_cpp_wrapper_OBJECTS = \
"CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o" \
"CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o"

# External object files for target thetaData_cpp_wrapper
thetaData_cpp_wrapper_EXTERNAL_OBJECTS =

thetaData_cpp_wrapper: CMakeFiles/thetaData_cpp_wrapper.dir/main.cpp.o
thetaData_cpp_wrapper: CMakeFiles/thetaData_cpp_wrapper.dir/client.cpp.o
thetaData_cpp_wrapper: CMakeFiles/thetaData_cpp_wrapper.dir/build.make
thetaData_cpp_wrapper: CMakeFiles/thetaData_cpp_wrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ericli/Documents/ThetaData/CPP_API_Wrapper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable thetaData_cpp_wrapper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thetaData_cpp_wrapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thetaData_cpp_wrapper.dir/build: thetaData_cpp_wrapper
.PHONY : CMakeFiles/thetaData_cpp_wrapper.dir/build

CMakeFiles/thetaData_cpp_wrapper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thetaData_cpp_wrapper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thetaData_cpp_wrapper.dir/clean

CMakeFiles/thetaData_cpp_wrapper.dir/depend:
	cd /Users/ericli/Documents/ThetaData/CPP_API_Wrapper && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ericli/Documents/ThetaData/CPP_API_Wrapper /Users/ericli/Documents/ThetaData/CPP_API_Wrapper /Users/ericli/Documents/ThetaData/CPP_API_Wrapper /Users/ericli/Documents/ThetaData/CPP_API_Wrapper /Users/ericli/Documents/ThetaData/CPP_API_Wrapper/CMakeFiles/thetaData_cpp_wrapper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thetaData_cpp_wrapper.dir/depend

