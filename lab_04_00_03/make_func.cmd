@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -O0 --coverage -c main.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -O0 --coverage -c get_words.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -O0 --coverage -c get_new_string.c
gcc --coverage -o app.exe get_new_string.o get_words.o main.o
PUSHD func
CALL ./all_test.cmd
PUSHD ..
gcov main.c