#!/bin/bash
cmake -S . -B /usr/bin/Ciyac/build 
cmake --build /usr/bin/Ciyac/build
if [ $? -eq 0 ]; then
    echo "Build works!"
    /usr/bin/Ciyac/build/ciya
else
    echo "Build failed!"
    exit 1
fi