#!/bin/sh

# disable filename globbing
set -f

cat - >> out

echo Content-type: text/plain
echo
