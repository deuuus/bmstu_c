@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c main.c process.c
gcc --coverage -o app.exe main.o process.o
PUSHD func
CALL ./all_test.cmd
PUSHD ..
gcov main.c