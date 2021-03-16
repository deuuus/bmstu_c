@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main.c get_between_average.c get_max_min.c --coverage -o app.exe
PUSHD func
CALL ./all_test.cmd
PUSHD ..
gcov main.c