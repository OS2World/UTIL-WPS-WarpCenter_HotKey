# makefile
# Created by IBM WorkFrame/2 MakeMake at 7:54:38 on 7 Oct 1997
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES:

.SUFFIXES: \
    .c .obj

.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Oc /Ge- /Gi /Ol /C %s

{g:\wckey}.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Oc /Ge- /Gi /Ol /C %s

all: \
    .\wckey.dll

.\wckey.dll: \
    .\wckey.obj \
    {$(LIB)}wckey.def
    @echo " Link::Linker "
    icc.exe @<<
     /B" /nobase /NOE"
     /Fewckey.dll
     wckey.def
     .\wckey.obj
<<

.\wckey.obj: \
    g:\wckey\wckey.c
