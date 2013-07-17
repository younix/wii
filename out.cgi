#!/bin/sh

RANGE=$(echo $HTTP_RANGE | sed -Ene 's/bytes=([[:digit:]]*)-/\1/p')
DIFF=0

while [ $DIFF -eq 0 ]; do
	sleep 0.5
	DIFF=$(($(stat -Lf '%z' out) - $RANGE))
done

echo Content-Length: $DIFF
echo Content-type: text/plain
echo
tail -c $DIFF out
