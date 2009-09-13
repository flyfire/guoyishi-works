# Microsoft Developer Studio Generated NMAKE File, Based on Exercise_3.dsp
!IF "$(CFG)" == ""
CFG=Exercise_3 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Exercise_3 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Exercise_3 - Win32 Release" && "$(CFG)" != "Exercise_3 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Exercise_3.mak" CFG="Exercise_3 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Exercise_3 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Exercise_3 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Exercise_3 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Exercise_3.exe"


CLEAN :
	-@erase "$(INTDIR)\Exercise_3.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Exercise_3.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\Exercise_3.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Exercise_3.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Exercise_3.pdb" /machine:I386 /out:"$(OUTDIR)\Exercise_3.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Exercise_3.obj"

"$(OUTDIR)\Exercise_3.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Exercise_3 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Exercise_3.exe"


CLEAN :
	-@erase "$(INTDIR)\Exercise_3.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Exercise_3.exe"
	-@erase "$(OUTDIR)\Exercise_3.ilk"
	-@erase "$(OUTDIR)\Exercise_3.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\Exercise_3.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Exercise_3.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=cv.lib cxcore.lib highgui.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Exercise_3.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Exercise_3.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Exercise_3.obj"

"$(OUTDIR)\Exercise_3.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Exercise_3.dep")
!INCLUDE "Exercise_3.dep"
!ELSE 
!MESSAGE Warning: cannot find "Exercise_3.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Exercise_3 - Win32 Release" || "$(CFG)" == "Exercise_3 - Win32 Debug"
SOURCE=.\Exercise_3.cpp

"$(INTDIR)\Exercise_3.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

