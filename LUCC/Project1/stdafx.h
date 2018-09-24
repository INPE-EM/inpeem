// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
//Language
#define DEFAULTLANGUAGE "br"

//Mode
#define NEWMODEL  1
#define OPENMODEL 2

//TabPages
#define DEFINITION	0
#define EQUATIONS	2
#define MAKEFILE	3

//Data values
#define TRUE	1
#define FALSE	0
#define NONE	0

//Miscellaneous
#define ROOTDIR			4
#define OPENROOTDIR		3
#define SECOND			1000
#define TWODIGITS		10
#define YOFFSET			30
#define XOFFSET			125
#define MAXEQUATIONS	50

//Equation File Address
#define EQUATIONADDRESS		"C:\\INPE-EM_LUCC\\equations.dat"

//Embedded TerraME Address
#define TERRAMEADDRESS		"C:\\INPE-EM_LUCC\\Terrame\\bin"

//.bat Address to call Terrame
#define BATADDRESS			"C:\\INPE-EM_LUCC\\Terrame\\bin\\inpeem.bat"