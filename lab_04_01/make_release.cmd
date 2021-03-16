@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -c main.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -c my_string.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -c unit_tests.c
gcc -o app.exe my_string.o unit_tests.o main.o