#!/bin/bash

program=checksum.exe

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

# calcualte checksum
checksum="$($program $1)"
checksum=${checksum: -4}

# get the new filename
new_filename="${1%.*}($checksum).${1#*.}"

# rename
mv $1 $new_filename

echo $1 " ---> " $new_filename

exit 0;
