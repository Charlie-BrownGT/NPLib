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
include Detectors/Sharc/CMakeFiles/NPSSharc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Detectors/Sharc/CMakeFiles/NPSSharc.dir/compiler_depend.make

# Include the progress variables for this target.
include Detectors/Sharc/CMakeFiles/NPSSharc.dir/progress.make

# Include the compile flags for this target's objects.
include Detectors/Sharc/CMakeFiles/NPSSharc.dir/flags.make

Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o: Detectors/Sharc/CMakeFiles/NPSSharc.dir/flags.make
Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o: Detectors/Sharc/Sharc.cc
Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o: Detectors/Sharc/CMakeFiles/NPSSharc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guy/software/nptool/nptool/NPSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o -MF CMakeFiles/NPSSharc.dir/Sharc.cc.o.d -o CMakeFiles/NPSSharc.dir/Sharc.cc.o -c /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc/Sharc.cc

Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NPSSharc.dir/Sharc.cc.i"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc/Sharc.cc > CMakeFiles/NPSSharc.dir/Sharc.cc.i

Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NPSSharc.dir/Sharc.cc.s"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc/Sharc.cc -o CMakeFiles/NPSSharc.dir/Sharc.cc.s

# Object files for target NPSSharc
NPSSharc_OBJECTS = \
"CMakeFiles/NPSSharc.dir/Sharc.cc.o"

# External object files for target NPSSharc
NPSSharc_EXTERNAL_OBJECTS =

lib/libNPSSharc.so: Detectors/Sharc/CMakeFiles/NPSSharc.dir/Sharc.cc.o
lib/libNPSSharc.so: Detectors/Sharc/CMakeFiles/NPSSharc.dir/build.make
lib/libNPSSharc.so: lib/libNPSCore.so
lib/libNPSSharc.so: lib/libNPSScorers.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4Tree.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4FR.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4GMocren.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4visHepRep.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4RayTracer.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4VRML.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4ToolsSG.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4OpenGL.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4vis_management.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4modeling.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4interfaces.so
lib/libNPSSharc.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
lib/libNPSSharc.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
lib/libNPSSharc.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4mctruth.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4geomtext.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4gdml.so
lib/libNPSSharc.so: /usr/lib/x86_64-linux-gnu/libxerces-c.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4error_propagation.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4readout.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4physicslists.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4run.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4event.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4tracking.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4parmodels.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4processes.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4analysis.so
lib/libNPSSharc.so: /usr/lib/x86_64-linux-gnu/libexpat.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4digits_hits.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4track.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4particles.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4geometry.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4materials.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4graphics_reps.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4intercoms.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4global.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4clhep.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4zlib.so
lib/libNPSSharc.so: /home/guy/software/geant4/geant4-v11.3.0-gdml-mt-install/lib/libG4ptl.so.3.0.0
lib/libNPSSharc.so: Detectors/Sharc/CMakeFiles/NPSSharc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guy/software/nptool/nptool/NPSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libNPSSharc.so"
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NPSSharc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Detectors/Sharc/CMakeFiles/NPSSharc.dir/build: lib/libNPSSharc.so
.PHONY : Detectors/Sharc/CMakeFiles/NPSSharc.dir/build

Detectors/Sharc/CMakeFiles/NPSSharc.dir/clean:
	cd /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc && $(CMAKE_COMMAND) -P CMakeFiles/NPSSharc.dir/cmake_clean.cmake
.PHONY : Detectors/Sharc/CMakeFiles/NPSSharc.dir/clean

Detectors/Sharc/CMakeFiles/NPSSharc.dir/depend:
	cd /home/guy/software/nptool/nptool/NPSimulation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guy/software/nptool/nptool/NPSimulation /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc /home/guy/software/nptool/nptool/NPSimulation /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc /home/guy/software/nptool/nptool/NPSimulation/Detectors/Sharc/CMakeFiles/NPSSharc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Detectors/Sharc/CMakeFiles/NPSSharc.dir/depend

