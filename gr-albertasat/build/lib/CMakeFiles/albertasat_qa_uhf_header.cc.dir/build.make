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
CMAKE_SOURCE_DIR = /home/dineth/ex2_sdr/gr-albertasat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dineth/ex2_sdr/gr-albertasat/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/flags.make

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/flags.make
lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o: ../lib/qa_uhf_header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dineth/ex2_sdr/gr-albertasat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o"
	cd /home/dineth/ex2_sdr/gr-albertasat/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o -c /home/dineth/ex2_sdr/gr-albertasat/lib/qa_uhf_header.cc

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.i"
	cd /home/dineth/ex2_sdr/gr-albertasat/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dineth/ex2_sdr/gr-albertasat/lib/qa_uhf_header.cc > CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.i

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.s"
	cd /home/dineth/ex2_sdr/gr-albertasat/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dineth/ex2_sdr/gr-albertasat/lib/qa_uhf_header.cc -o CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.s

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.requires:

.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.requires

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.provides: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.requires
	$(MAKE) -f lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/build.make lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.provides.build
.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.provides

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.provides.build: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o


# Object files for target albertasat_qa_uhf_header.cc
albertasat_qa_uhf_header_cc_OBJECTS = \
"CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o"

# External object files for target albertasat_qa_uhf_header.cc
albertasat_qa_uhf_header_cc_EXTERNAL_OBJECTS =

lib/albertasat_qa_uhf_header.cc: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o
lib/albertasat_qa_uhf_header.cc: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/build.make
lib/albertasat_qa_uhf_header.cc: lib/libgnuradio-albertasat.so.v1.0-compat-xxx-xunknown
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
lib/albertasat_qa_uhf_header.cc: /usr/local/lib/libgnuradio-runtime.so.v3.8.2.0-77-g03a5570e
lib/albertasat_qa_uhf_header.cc: /usr/local/lib/libgnuradio-pmt.so.v3.8.2.0-77-g03a5570e
lib/albertasat_qa_uhf_header.cc: /usr/local/lib/libvolk.so.2.0
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_regex.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_thread.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_system.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/liblog4cpp.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libgmpxx.so
lib/albertasat_qa_uhf_header.cc: /usr/lib/x86_64-linux-gnu/libgmp.so
lib/albertasat_qa_uhf_header.cc: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dineth/ex2_sdr/gr-albertasat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable albertasat_qa_uhf_header.cc"
	cd /home/dineth/ex2_sdr/gr-albertasat/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/albertasat_qa_uhf_header.cc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/build: lib/albertasat_qa_uhf_header.cc

.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/build

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/requires: lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/qa_uhf_header.cc.o.requires

.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/requires

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/clean:
	cd /home/dineth/ex2_sdr/gr-albertasat/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/albertasat_qa_uhf_header.cc.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/clean

lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/depend:
	cd /home/dineth/ex2_sdr/gr-albertasat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dineth/ex2_sdr/gr-albertasat /home/dineth/ex2_sdr/gr-albertasat/lib /home/dineth/ex2_sdr/gr-albertasat/build /home/dineth/ex2_sdr/gr-albertasat/build/lib /home/dineth/ex2_sdr/gr-albertasat/build/lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/albertasat_qa_uhf_header.cc.dir/depend

