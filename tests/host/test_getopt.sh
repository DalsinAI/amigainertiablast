#!/bin/sh
# Upstream's lib/getopt restarts at optind = 0 (tests/host/getopt_twice.c).
set -eu
cd "$(dirname "$0")/../.."
T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
${CC:-cc} -std=gnu11 -w -Ilib -o "$T/getopt_twice" tests/host/getopt_twice.c lib/getopt.c lib/getopt1.c
"$T/getopt_twice"
