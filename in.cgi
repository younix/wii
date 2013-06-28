#!/bin/sh

# disable filename globbing
set -f

cat - >> in

echo Content-type: text/plain
echo
