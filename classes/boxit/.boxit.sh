#!/usr/bin/env bash
_project_dir="/home/syafiq/Documents/JetBrains/CLion/hackerrank.cpp/"
_this_name=".boxit.sh"
_path=$(readlink -f .boxit.sh | replace ${_project_dir} "" | replace ${_this_name} "")
cd ../../
find ${_path} -type f \( -iname "*.hpp" -or -iname "*.cpp" -or -iname "*.cxx" -or -iname "*.c" -or -iname "*.h" \) -printf '%p\n' | sort | cat > ${_path}list.properties
