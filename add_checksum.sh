#!/bin/bash

program=checksum.out

# check input name
if [ -z $1 ]; then
    echo please input filename.
    exit 1;
fi

# check file is exist
if ! [ -e $1 ]; then
    echo $1 is not exist.
    exit 1;
fi

# check checksum.out is maked.
if ! checksum_program="$(type -p "$program")" || [ -z "$checksum_program" ]; then
    make
fi

# calcualte checksum
checksum="$($program $1)"
checksum=${checksum: -4}

# get the new filename
new_filename="$1_($checksum)"

# rename
mv $1 $new_filename

echo origin filename: $1
echo $new_filename

exit 0;
