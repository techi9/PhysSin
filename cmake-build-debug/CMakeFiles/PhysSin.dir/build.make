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
CMAKE_COMMAND = "E:\programms\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\programms\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tucha\Desktop\C_source\PhysSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PhysSin.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PhysSin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PhysSin.dir/flags.make

CMakeFiles/PhysSin.dir/main.cpp.obj: CMakeFiles/PhysSin.dir/flags.make
CMakeFiles/PhysSin.dir/main.cpp.obj: CMakeFiles/PhysSin.dir/includes_CXX.rsp
CMakeFiles/PhysSin.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PhysSin.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PhysSin.dir\main.cpp.obj -c C:\Users\tucha\Desktop\C_source\PhysSim\main.cpp

CMakeFiles/PhysSin.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhysSin.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tucha\Desktop\C_source\PhysSim\main.cpp > CMakeFiles\PhysSin.dir\main.cpp.i

CMakeFiles/PhysSin.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhysSin.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tucha\Desktop\C_source\PhysSim\main.cpp -o CMakeFiles\PhysSin.dir\main.cpp.s

CMakeFiles/PhysSin.dir/GameBody.cpp.obj: CMakeFiles/PhysSin.dir/flags.make
CMakeFiles/PhysSin.dir/GameBody.cpp.obj: CMakeFiles/PhysSin.dir/includes_CXX.rsp
CMakeFiles/PhysSin.dir/GameBody.cpp.obj: ../GameBody.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PhysSin.dir/GameBody.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PhysSin.dir\GameBody.cpp.obj -c C:\Users\tucha\Desktop\C_source\PhysSim\GameBody.cpp

CMakeFiles/PhysSin.dir/GameBody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhysSin.dir/GameBody.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tucha\Desktop\C_source\PhysSim\GameBody.cpp > CMakeFiles\PhysSin.dir\GameBody.cpp.i

CMakeFiles/PhysSin.dir/GameBody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhysSin.dir/GameBody.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tucha\Desktop\C_source\PhysSim\GameBody.cpp -o CMakeFiles\PhysSin.dir\GameBody.cpp.s

# Object files for target PhysSin
PhysSin_OBJECTS = \
"CMakeFiles/PhysSin.dir/main.cpp.obj" \
"CMakeFiles/PhysSin.dir/GameBody.cpp.obj"

# External object files for target PhysSin
PhysSin_EXTERNAL_OBJECTS =

PhysSin.exe: CMakeFiles/PhysSin.dir/main.cpp.obj
PhysSin.exe: CMakeFiles/PhysSin.dir/GameBody.cpp.obj
PhysSin.exe: CMakeFiles/PhysSin.dir/build.make
PhysSin.exe: C:/SFML/lib/libsfml-system-d.a
PhysSin.exe: C:/SFML/lib/libsfml-window-d.a
PhysSin.exe: C:/SFML/lib/libsfml-graphics-d.a
PhysSin.exe: C:/SFML/lib/libsfml-network-d.a
PhysSin.exe: C:/SFML/lib/libsfml-audio-d.a
PhysSin.exe: CMakeFiles/PhysSin.dir/linklibs.rsp
PhysSin.exe: CMakeFiles/PhysSin.dir/objects1.rsp
PhysSin.exe: CMakeFiles/PhysSin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PhysSin.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PhysSin.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PhysSin.dir/build: PhysSin.exe
.PHONY : CMakeFiles/PhysSin.dir/build

CMakeFiles/PhysSin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PhysSin.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PhysSin.dir/clean

CMakeFiles/PhysSin.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tucha\Desktop\C_source\PhysSim C:\Users\tucha\Desktop\C_source\PhysSim C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug C:\Users\tucha\Desktop\C_source\PhysSim\cmake-build-debug\CMakeFiles\PhysSin.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PhysSin.dir/depend

