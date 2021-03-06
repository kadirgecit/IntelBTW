#!/bin/sh
target_file="${PROJECT_DIR}/include/FwBinary.cpp"
if [ -f "$target_file" ]; then
exit 0
fi
while [ $# -gt 0 ];
do
    case $1 in
    -P) fw_files=$2
    shift
    ;;

    esac
    shift
done

script_file="${PROJECT_DIR}/scripts/"
python -c 'import sys;sys.path.append("'$script_file'");from zlib_compress_fw import *;process_files("'${target_file}'", "'$fw_files'")'
