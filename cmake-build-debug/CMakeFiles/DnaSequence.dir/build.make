# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ruti/Desktop/c++/DnaSequence

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruti/Desktop/c++/DnaSequence/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DnaSequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DnaSequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DnaSequence.dir/flags.make

CMakeFiles/DnaSequence.dir/main.cpp.o: CMakeFiles/DnaSequence.dir/flags.make
CMakeFiles/DnaSequence.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DnaSequence.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaSequence.dir/main.cpp.o -c /home/ruti/Desktop/c++/DnaSequence/main.cpp

CMakeFiles/DnaSequence.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaSequence.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ruti/Desktop/c++/DnaSequence/main.cpp > CMakeFiles/DnaSequence.dir/main.cpp.i

CMakeFiles/DnaSequence.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaSequence.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ruti/Desktop/c++/DnaSequence/main.cpp -o CMakeFiles/DnaSequence.dir/main.cpp.s

CMakeFiles/DnaSequence.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DnaSequence.dir/main.cpp.o.requires

CMakeFiles/DnaSequence.dir/main.cpp.o.provides: CMakeFiles/DnaSequence.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DnaSequence.dir/build.make CMakeFiles/DnaSequence.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DnaSequence.dir/main.cpp.o.provides

CMakeFiles/DnaSequence.dir/main.cpp.o.provides.build: CMakeFiles/DnaSequence.dir/main.cpp.o


CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o: CMakeFiles/DnaSequence.dir/flags.make
CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o: ../dna_sequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o -c /home/ruti/Desktop/c++/DnaSequence/dna_sequence.cpp

CMakeFiles/DnaSequence.dir/dna_sequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaSequence.dir/dna_sequence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ruti/Desktop/c++/DnaSequence/dna_sequence.cpp > CMakeFiles/DnaSequence.dir/dna_sequence.cpp.i

CMakeFiles/DnaSequence.dir/dna_sequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaSequence.dir/dna_sequence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ruti/Desktop/c++/DnaSequence/dna_sequence.cpp -o CMakeFiles/DnaSequence.dir/dna_sequence.cpp.s

CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.requires:

.PHONY : CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.requires

CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.provides: CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.requires
	$(MAKE) -f CMakeFiles/DnaSequence.dir/build.make CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.provides.build
.PHONY : CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.provides

CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.provides.build: CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o


CMakeFiles/DnaSequence.dir/test_dna.cpp.o: CMakeFiles/DnaSequence.dir/flags.make
CMakeFiles/DnaSequence.dir/test_dna.cpp.o: ../test_dna.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DnaSequence.dir/test_dna.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaSequence.dir/test_dna.cpp.o -c /home/ruti/Desktop/c++/DnaSequence/test_dna.cpp

CMakeFiles/DnaSequence.dir/test_dna.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaSequence.dir/test_dna.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ruti/Desktop/c++/DnaSequence/test_dna.cpp > CMakeFiles/DnaSequence.dir/test_dna.cpp.i

CMakeFiles/DnaSequence.dir/test_dna.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaSequence.dir/test_dna.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ruti/Desktop/c++/DnaSequence/test_dna.cpp -o CMakeFiles/DnaSequence.dir/test_dna.cpp.s

CMakeFiles/DnaSequence.dir/test_dna.cpp.o.requires:

.PHONY : CMakeFiles/DnaSequence.dir/test_dna.cpp.o.requires

CMakeFiles/DnaSequence.dir/test_dna.cpp.o.provides: CMakeFiles/DnaSequence.dir/test_dna.cpp.o.requires
	$(MAKE) -f CMakeFiles/DnaSequence.dir/build.make CMakeFiles/DnaSequence.dir/test_dna.cpp.o.provides.build
.PHONY : CMakeFiles/DnaSequence.dir/test_dna.cpp.o.provides

CMakeFiles/DnaSequence.dir/test_dna.cpp.o.provides.build: CMakeFiles/DnaSequence.dir/test_dna.cpp.o


CMakeFiles/DnaSequence.dir/val_error.cpp.o: CMakeFiles/DnaSequence.dir/flags.make
CMakeFiles/DnaSequence.dir/val_error.cpp.o: ../val_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DnaSequence.dir/val_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DnaSequence.dir/val_error.cpp.o -c /home/ruti/Desktop/c++/DnaSequence/val_error.cpp

CMakeFiles/DnaSequence.dir/val_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DnaSequence.dir/val_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ruti/Desktop/c++/DnaSequence/val_error.cpp > CMakeFiles/DnaSequence.dir/val_error.cpp.i

CMakeFiles/DnaSequence.dir/val_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DnaSequence.dir/val_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ruti/Desktop/c++/DnaSequence/val_error.cpp -o CMakeFiles/DnaSequence.dir/val_error.cpp.s

CMakeFiles/DnaSequence.dir/val_error.cpp.o.requires:

.PHONY : CMakeFiles/DnaSequence.dir/val_error.cpp.o.requires

CMakeFiles/DnaSequence.dir/val_error.cpp.o.provides: CMakeFiles/DnaSequence.dir/val_error.cpp.o.requires
	$(MAKE) -f CMakeFiles/DnaSequence.dir/build.make CMakeFiles/DnaSequence.dir/val_error.cpp.o.provides.build
.PHONY : CMakeFiles/DnaSequence.dir/val_error.cpp.o.provides

CMakeFiles/DnaSequence.dir/val_error.cpp.o.provides.build: CMakeFiles/DnaSequence.dir/val_error.cpp.o


# Object files for target DnaSequence
DnaSequence_OBJECTS = \
"CMakeFiles/DnaSequence.dir/main.cpp.o" \
"CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o" \
"CMakeFiles/DnaSequence.dir/test_dna.cpp.o" \
"CMakeFiles/DnaSequence.dir/val_error.cpp.o"

# External object files for target DnaSequence
DnaSequence_EXTERNAL_OBJECTS =

DnaSequence: CMakeFiles/DnaSequence.dir/main.cpp.o
DnaSequence: CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o
DnaSequence: CMakeFiles/DnaSequence.dir/test_dna.cpp.o
DnaSequence: CMakeFiles/DnaSequence.dir/val_error.cpp.o
DnaSequence: CMakeFiles/DnaSequence.dir/build.make
DnaSequence: CMakeFiles/DnaSequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DnaSequence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DnaSequence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DnaSequence.dir/build: DnaSequence

.PHONY : CMakeFiles/DnaSequence.dir/build

CMakeFiles/DnaSequence.dir/requires: CMakeFiles/DnaSequence.dir/main.cpp.o.requires
CMakeFiles/DnaSequence.dir/requires: CMakeFiles/DnaSequence.dir/dna_sequence.cpp.o.requires
CMakeFiles/DnaSequence.dir/requires: CMakeFiles/DnaSequence.dir/test_dna.cpp.o.requires
CMakeFiles/DnaSequence.dir/requires: CMakeFiles/DnaSequence.dir/val_error.cpp.o.requires

.PHONY : CMakeFiles/DnaSequence.dir/requires

CMakeFiles/DnaSequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DnaSequence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DnaSequence.dir/clean

CMakeFiles/DnaSequence.dir/depend:
	cd /home/ruti/Desktop/c++/DnaSequence/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruti/Desktop/c++/DnaSequence /home/ruti/Desktop/c++/DnaSequence /home/ruti/Desktop/c++/DnaSequence/cmake-build-debug /home/ruti/Desktop/c++/DnaSequence/cmake-build-debug /home/ruti/Desktop/c++/DnaSequence/cmake-build-debug/CMakeFiles/DnaSequence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DnaSequence.dir/depend

