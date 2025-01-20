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
CMAKE_SOURCE_DIR = /home/guy/software/nptool/nptool/NPSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guy/software/nptool/nptool/NPSimulation

# Include any dependencies generated for this target.
include Detectors/QQQ/CMakeFiles/NPSQQQ.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Detectors/QQQ/CMakeFiles/NPSQQQ.dir/compiler_depend.make

# Include the progress variables for this target.
include Detectors/QQQ/CMakeFiles/NPSQQQ.dir/progress.make

# Include the compile flags for this target's objects.
include Detectors/QQQ/CMakeFiles/NPSQQQ.dir/flags.make

Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o: Detectors/QQQ/CMakeFiles/NPSQQQ.dir/flags.make
Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o: Detectors/QQQ/QQQ.cc
Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o: Detectors/QQQ/CMakeFiles/NPSQQQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o -MF CMakeFiles/NPSQQQ.dir/QQQ.cc.o.d -o CMakeFiles/NPSQQQ.dir/QQQ.cc.o -c /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ/QQQ.cc

Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPSQQQ.dir/QQQ.cc.i"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ/QQQ.cc > CMakeFiles/NPSQQQ.dir/QQQ.cc.i

Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPSQQQ.dir/QQQ.cc.s"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ/QQQ.cc -o CMakeFiles/NPSQQQ.dir/QQQ.cc.s

# Object files for target NPSQQQ
NPSQQQ_OBJECTS = \
"CMakeFiles/NPSQQQ.dir/QQQ.cc.o"

# External object files for target NPSQQQ
NPSQQQ_EXTERNAL_OBJECTS =

lib/libNPSQQQ.so: Detectors/QQQ/CMakeFiles/NPSQQQ.dir/QQQ.cc.o
lib/libNPSQQQ.so: Detectors/QQQ/CMakeFiles/NPSQQQ.dir/build.make
lib/libNPSQQQ.so: lib/libNPSCore.so
lib/libNPSQQQ.so: lib/libNPSScorers.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4Tree.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4FR.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4GMocren.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4visHepRep.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4RayTracer.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4VRML.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4ToolsSG.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4OpenGL.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4vis_management.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4modeling.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4interfaces.so
lib/libNPSQQQ.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
lib/libNPSQQQ.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
lib/libNPSQQQ.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4mctruth.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4geomtext.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4gdml.so
lib/libNPSQQQ.so: /usr/lib/x86_64-linux-gnu/libxerces-c.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4error_propagation.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4readout.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4physicslists.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4run.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4event.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4tracking.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4parmodels.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4processes.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4analysis.so
lib/libNPSQQQ.so: /usr/lib/x86_64-linux-gnu/libexpat.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4digits_hits.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4track.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4particles.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4geometry.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4materials.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4graphics_reps.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4intercoms.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4global.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4clhep.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4zlib.so
lib/libNPSQQQ.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4ptl.so.3.0.0
lib/libNPSQQQ.so: Detectors/QQQ/CMakeFiles/NPSQQQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guy/software/nptool/nptool/NPSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libNPSQQQ.so"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NPSQQQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Detectors/QQQ/CMakeFiles/NPSQQQ.dir/build: lib/libNPSQQQ.so
.PHONY : Detectors/QQQ/CMakeFiles/NPSQQQ.dir/build

Detectors/QQQ/CMakeFiles/NPSQQQ.dir/clean:
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ && $(CMAKE_COMMAND) -P CMakeFiles/NPSQQQ.dir/cmake_clean.cmake
.PHONY : Detectors/QQQ/CMakeFiles/NPSQQQ.dir/clean

Detectors/QQQ/CMakeFiles/NPSQQQ.dir/depend:
	cd /home/guy/software/nptool/nptool/NPSimulation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/software/nptool/nptool/NPSimulation /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ /home/guy/software/nptool/nptool/NPSimulation /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ /home/guy/software/nptool/nptool/NPSimulation/Detectors/QQQ/CMakeFiles/NPSQQQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Detectors/QQQ/CMakeFiles/NPSQQQ.dir/depend

