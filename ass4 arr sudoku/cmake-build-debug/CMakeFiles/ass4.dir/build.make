# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ori\Desktop\CS\ass4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ori\Desktop\CS\ass4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ass4.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ass4.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ass4.dir\flags.make

CMakeFiles\ass4.dir\main.c.obj: CMakeFiles\ass4.dir\flags.make
CMakeFiles\ass4.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ori\Desktop\CS\ass4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ass4.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\ass4.dir\main.c.obj /FdCMakeFiles\ass4.dir\ /FS -c C:\Users\ori\Desktop\CS\ass4\main.c
<<

CMakeFiles\ass4.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ass4.dir/main.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\ass4.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ori\Desktop\CS\ass4\main.c
<<

CMakeFiles\ass4.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ass4.dir/main.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass4.dir\main.c.s /c C:\Users\ori\Desktop\CS\ass4\main.c
<<

CMakeFiles\ass4.dir\ass4.c.obj: CMakeFiles\ass4.dir\flags.make
CMakeFiles\ass4.dir\ass4.c.obj: ..\ass4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ori\Desktop\CS\ass4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ass4.dir/ass4.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\ass4.dir\ass4.c.obj /FdCMakeFiles\ass4.dir\ /FS -c C:\Users\ori\Desktop\CS\ass4\ass4.c
<<

CMakeFiles\ass4.dir\ass4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ass4.dir/ass4.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\ass4.dir\ass4.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ori\Desktop\CS\ass4\ass4.c
<<

CMakeFiles\ass4.dir\ass4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ass4.dir/ass4.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\ass4.dir\ass4.c.s /c C:\Users\ori\Desktop\CS\ass4\ass4.c
<<

# Object files for target ass4
ass4_OBJECTS = \
"CMakeFiles\ass4.dir\main.c.obj" \
"CMakeFiles\ass4.dir\ass4.c.obj"

# External object files for target ass4
ass4_EXTERNAL_OBJECTS =

ass4.exe: CMakeFiles\ass4.dir\main.c.obj
ass4.exe: CMakeFiles\ass4.dir\ass4.c.obj
ass4.exe: CMakeFiles\ass4.dir\build.make
ass4.exe: CMakeFiles\ass4.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ori\Desktop\CS\ass4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ass4.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ass4.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ass4.dir\objects1.rsp @<<
 /out:ass4.exe /implib:ass4.lib /pdb:C:\Users\ori\Desktop\CS\ass4\cmake-build-debug\ass4.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ass4.dir\build: ass4.exe

.PHONY : CMakeFiles\ass4.dir\build

CMakeFiles\ass4.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ass4.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ass4.dir\clean

CMakeFiles\ass4.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\ori\Desktop\CS\ass4 C:\Users\ori\Desktop\CS\ass4 C:\Users\ori\Desktop\CS\ass4\cmake-build-debug C:\Users\ori\Desktop\CS\ass4\cmake-build-debug C:\Users\ori\Desktop\CS\ass4\cmake-build-debug\CMakeFiles\ass4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ass4.dir\depend

