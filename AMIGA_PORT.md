Inertia Blast for GFOS
======================

A port of Inertia Blast, Dennis Payne's GPL remake of Thrust (Peter
Ekberg's Thrust for MS-DOS, after the C64 and BBC Micro game), from
https://github.com/dulsi/thrust at commit
27fe34f590f924240c18d47624a3a7bba2ba59f0 (version 0.93), for GFOS: AmigaOS
3.2 with GFOpenUp, on a 68040 or 68060 with an FPU, on GFOpenUp's SDL 2.

Steal the energy pods: lift each one on your tractor beam, mind the
weight it adds to the ship, and keep clear of the guns.

Status: built in Cradle's os32-gcc16-open6 stove; not yet run in a lab.


What you need
-------------

- GFOS: AmigaOS 3.2 with GFOpenUp 0.8.26 or later, which installs
  LIBS:GFOpenGPU/SDL2.module and SDL2_mixer.module.
- A 68040 or 68060 with an FPU (not an LC040 or EC040), an RTG screen (or
  the AmiCradle lab), and about 2 MB of free memory.
- Nothing else: the levels, pictures and sounds are in the program.


How to play
-----------

Run Install-InertiaBlast (or copy the InertiaBlast drawer where you want
it), then double-click InertiaBlast, or from a Shell:

    cd InertiaBlast
    InertiaBlast [-w] [-2] [-nodemo] [-nosoundeffects] [-step] [-fps]

-w runs in a window, -2 doubles the window, -step draws every third frame
(for a slower Amiga). The keys are in the drawer's Controls file (the Help
key shows it): A and S turn, Right Shift thrusts, Return fires, Space lifts
the pod and raises the shield, P pauses, Esc ends the game. C on the title
screen changes them.

The settings (thrustrc), the statistics and the high scores are kept in
the drawer's User drawer; Install-InertiaBlast keeps it when it updates
the game.


Building
--------

    make -f amiga/Makefile.amigaos -j4 STOVE=/path/to/os32-gcc16-open6

or, in Cradle, stove_build with the os32-gcc16-open6 stove and target
package (package/build-amiga.sh), which also packs
InertiaBlast-VERSION-68040.lha.


What was changed
----------------

- src/config.h: the Amiga build takes amiga/config_amiga.h (what libnix
  has; the high scores in PROGDIR:User/). getopt_long_only is upstream's
  own lib/getopt.c and getopt1.c, which restart when the game sets optind
  to 0.
- src/conf.c: the data path is PROGDIR:, the user path PROGDIR:User/.
- tests/host/test_getopt.sh: upstream's getopt gives the same options on
  both scans and none for a Workbench start (argc 0).
- src/sdlkey.c: thrust is Right Shift, as an Amiga keyboard has no right
  Ctrl.
- amiga/amiga_start.c: 256 KB of stack, the $VER string, PROGDIR:User made
  at start.
- amiga/: the Makefile, the GlowIcons (our own art), the Installer script
  and its spec.

The AmiCradle Team.
