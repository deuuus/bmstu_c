@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -g -pg -O0 --coverage main.c -o app.exe
PUSHD func
CALL ./all_test.cmd
PUSHD ..
gcov main.c