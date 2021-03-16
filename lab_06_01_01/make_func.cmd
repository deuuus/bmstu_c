@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c main.c utilities.c
gcc --coverage -o app.exe main.o utilities.o
PUSHD func
CALL ./all_tests.cmd
PUSHD ..
gcov main.c