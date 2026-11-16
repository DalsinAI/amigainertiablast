/* src/config.h for the Amiga build (AmigaOS 3.2 with libnix): what the
 * stove's C library has. getopt_long_only comes from upstream's own lib/
 * (GNU getopt), which starts its scan again when optind is set to 0, as
 * the game does in graphicsinit(). The high scores and the settings go to
 * PROGDIR:User/, made at start (amiga/amiga_start.c).
 * Copyright (c) 2026 AmiCradle Team. GPL 2 or later, like Inertia Blast. */
#define HAVE_ATEXIT 1
#define HAVE_FCNTL_H 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_RANDOM 1
#define HAVE_SOUND 1
#define HAVE_STRDUP 1
#define HAVE_UNISTD_H 1
#define HAVE_USLEEP 1
#define HIGHSCOREFILE "PROGDIR:User/thrust.highscore"
#define PACKAGE "inertiablast"
#define PACKAGE_BUGREPORT "dulsi@identicalsoftware.com"
#define PACKAGE_NAME "inertiablast"
#define PACKAGE_STRING "inertiablast 0.93"
#define PACKAGE_TARNAME "inertiablast"
#define PACKAGE_VERSION "0.93"
#define PRINTF_RETURN 1
#define RETSIGTYPE void
#define VERSION "0.93"
