#!/bin/sh

for PPM_FILE in *.ppm; do
    BASENAME="${PPM_FILE%%.*}"
    JPG_FILE="${BASENAME}.jpg"
    rm -f $JPG_FILE
    cat $PPM_FILE | pnmtojpeg > $JPG_FILE
done