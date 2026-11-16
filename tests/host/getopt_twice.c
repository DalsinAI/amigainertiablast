/* The game scans its arguments twice (main(), then graphicsinit() after
 * optind = 0); upstream's lib/getopt.c, which the Amiga build uses, must
 * give the same options both times, long ones as "-name" too.
 * GPL 2 or later, Copyright (c) 2026 AmiCradle Team. */
#include <stdio.h>
#include <string.h>
#include "../../lib/getopt.h"

static int scan(int argc, char **argv, char *seen)
{
	static struct option longopts[] = {
		{ "windowed", no_argument, 0, 'w' },
		{ "double", no_argument, 0, '2' },
		{ "nodemo", no_argument, 0, 'd' },
		{ "gamma", required_argument, 0, 'c' },
		{ 0, 0, 0, 0 }
	};
	int c, n = 0;
	optind = 0;
	while ((c = getopt_long_only(argc, argv, "w2dc:", longopts, 0)) != EOF) {
		if (c == '?')
			return -1;
		seen[n++] = (char)c;
		if (c == 'c' && strcmp(optarg, "1.5"))
			return -1;
	}
	seen[n] = 0;
	return n;
}

int main(void)
{
	char *argv[] = { "InertiaBlast", "-windowed", "--nodemo", "-2", "-gamma=1.5", 0 };
	char a[16], b[16];
	int argc = 5;
	if (scan(argc, argv, a) != 4 || scan(argc, argv, b) != 4 || strcmp(a, "wd2c") || strcmp(a, b)) {
		printf("FAIL: first \"%s\", second \"%s\"\n", a, b);
		return 1;
	}
	/* from Workbench libnix gives argc 0 */
	if (scan(0, argv, a) != 0) {
		printf("FAIL: argc 0\n");
		return 1;
	}
	printf("PASS: both scans gave %s; argc 0 gives none\n", b);
	return 0;
}
