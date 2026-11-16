/* The Amiga port's start: the stack, the version string and PROGDIR:User
 * (the settings, the statistics and the high scores), made before main()
 * so the high score list can be written whichever file the game saves
 * first.
 * Copyright (c) 2026 AmiCradle Team. GPL 2 or later, like Inertia Blast. */
#include <sys/stat.h>

/* A Shell gives 4 KB of stack; SDL 2 wants more. libnix's startup sets
 * this much up. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) =
    "$VER: InertiaBlast 0.93 (16.11.2026)";

static void __attribute__((constructor)) amiga_user_drawer(void)
{
	mkdir("PROGDIR:User", 0755);
}
