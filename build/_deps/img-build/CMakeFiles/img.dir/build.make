# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build

# Include any dependencies generated for this target.
include _deps/img-build/CMakeFiles/img.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/img-build/CMakeFiles/img.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/img-build/CMakeFiles/img.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/img-build/CMakeFiles/img.dir/flags.make

_deps/img-build/CMakeFiles/img.dir/codegen:
.PHONY : _deps/img-build/CMakeFiles/img.dir/codegen

_deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o: _deps/img-build/CMakeFiles/img.dir/flags.make
_deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o: _deps/img-src/src/Load.cpp
_deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o: _deps/img-build/CMakeFiles/img.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o -MF CMakeFiles/img.dir/src/Load.cpp.o.d -o CMakeFiles/img.dir/src/Load.cpp.o -c /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Load.cpp

_deps/img-build/CMakeFiles/img.dir/src/Load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/img.dir/src/Load.cpp.i"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Load.cpp > CMakeFiles/img.dir/src/Load.cpp.i

_deps/img-build/CMakeFiles/img.dir/src/Load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/img.dir/src/Load.cpp.s"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Load.cpp -o CMakeFiles/img.dir/src/Load.cpp.s

_deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o: _deps/img-build/CMakeFiles/img.dir/flags.make
_deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o: _deps/img-src/src/Save.cpp
_deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o: _deps/img-build/CMakeFiles/img.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o -MF CMakeFiles/img.dir/src/Save.cpp.o.d -o CMakeFiles/img.dir/src/Save.cpp.o -c /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Save.cpp

_deps/img-build/CMakeFiles/img.dir/src/Save.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/img.dir/src/Save.cpp.i"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Save.cpp > CMakeFiles/img.dir/src/Save.cpp.i

_deps/img-build/CMakeFiles/img.dir/src/Save.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/img.dir/src/Save.cpp.s"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src/src/Save.cpp -o CMakeFiles/img.dir/src/Save.cpp.s

# Object files for target img
img_OBJECTS = \
"CMakeFiles/img.dir/src/Load.cpp.o" \
"CMakeFiles/img.dir/src/Save.cpp.o"

# External object files for target img
img_EXTERNAL_OBJECTS =

_deps/img-build/libimg.a: _deps/img-build/CMakeFiles/img.dir/src/Load.cpp.o
_deps/img-build/libimg.a: _deps/img-build/CMakeFiles/img.dir/src/Save.cpp.o
_deps/img-build/libimg.a: _deps/img-build/CMakeFiles/img.dir/build.make
_deps/img-build/libimg.a: _deps/img-build/CMakeFiles/img.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libimg.a"
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && $(CMAKE_COMMAND) -P CMakeFiles/img.dir/cmake_clean_target.cmake
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/img.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/img-build/CMakeFiles/img.dir/build: _deps/img-build/libimg.a
.PHONY : _deps/img-build/CMakeFiles/img.dir/build

_deps/img-build/CMakeFiles/img.dir/clean:
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build && $(CMAKE_COMMAND) -P CMakeFiles/img.dir/cmake_clean.cmake
.PHONY : _deps/img-build/CMakeFiles/img.dir/clean

_deps/img-build/CMakeFiles/img.dir/depend:
	cd /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-src /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build /Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/img-build/CMakeFiles/img.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/img-build/CMakeFiles/img.dir/depend
