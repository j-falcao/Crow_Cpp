@echo off


cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -B build . -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++

