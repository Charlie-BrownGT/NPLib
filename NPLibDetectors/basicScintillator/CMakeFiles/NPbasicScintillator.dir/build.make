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
CMAKE_SOURCE_DIR = /home/guy/software/nptool/nptool/NPLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guy/software/nptool/nptool/NPLib

# Include any dependencies generated for this target.
include Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.make

# Include the progress variables for this target.
include Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/progress.make

# Include the compile flags for this target's objects.
include Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make

Detectors/basicScintillator/TbasicScintillatorDataDict.cxx: Detectors/basicScintillator/TbasicScintillatorData.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating TbasicScintillatorDataDict.cxx"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && ../../scripts/build_dict.sh TbasicScintillatorData.h TbasicScintillatorDataDict.cxx TbasicScintillatorData.rootmap libNPbasicScintillator.dylib

Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx: Detectors/basicScintillator/TbasicScintillatorPhysics.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating TbasicScintillatorPhysicsDict.cxx"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && ../../scripts/build_dict.sh TbasicScintillatorPhysics.h TbasicScintillatorPhysicsDict.cxx TbasicScintillatorPhysics.rootmap libNPbasicScintillator.dylib

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o: Detectors/basicScintillator/TbasicScintillatorSpectra.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o -MF CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o.d -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o -c /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorSpectra.cxx

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.i"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorSpectra.cxx > CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.i

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.s"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorSpectra.cxx -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.s

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o: Detectors/basicScintillator/TbasicScintillatorData.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o -MF CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o.d -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o -c /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorData.cxx

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.i"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorData.cxx > CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.i

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.s"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorData.cxx -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.s

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o: Detectors/basicScintillator/TbasicScintillatorPhysics.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o -MF CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o.d -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o -c /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysics.cxx

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.i"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysics.cxx > CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.i

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.s"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysics.cxx -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.s

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o: Detectors/basicScintillator/TbasicScintillatorDataDict.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o -MF CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o.d -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o -c /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorDataDict.cxx

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.i"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorDataDict.cxx > CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.i

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.s"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorDataDict.cxx -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.s

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/flags.make
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o: Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o -MF CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o.d -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o -c /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.i"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx > CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.i

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.s"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx -o CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.s

# Object files for target NPbasicScintillator
NPbasicScintillator_OBJECTS = \
"CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o" \
"CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o" \
"CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o" \
"CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o" \
"CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o"

# External object files for target NPbasicScintillator
NPbasicScintillator_EXTERNAL_OBJECTS =

lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorSpectra.cxx.o
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorData.cxx.o
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysics.cxx.o
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorDataDict.cxx.o
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/TbasicScintillatorPhysicsDict.cxx.o
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/build.make
lib/libNPbasicScintillator.so: lib/libNPCore.so
lib/libNPbasicScintillator.so: Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guy/software/nptool/nptool/NPLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../lib/libNPbasicScintillator.so"
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NPbasicScintillator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/build: lib/libNPbasicScintillator.so
.PHONY : Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/build

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/clean:
	cd /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator && $(CMAKE_COMMAND) -P CMakeFiles/NPbasicScintillator.dir/cmake_clean.cmake
.PHONY : Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/clean

Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/depend: Detectors/basicScintillator/TbasicScintillatorDataDict.cxx
Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/depend: Detectors/basicScintillator/TbasicScintillatorPhysicsDict.cxx
	cd /home/guy/software/nptool/nptool/NPLib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/software/nptool/nptool/NPLib /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator /home/guy/software/nptool/nptool/NPLib /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator /home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Detectors/basicScintillator/CMakeFiles/NPbasicScintillator.dir/depend

