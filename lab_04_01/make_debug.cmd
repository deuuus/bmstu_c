@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -g3 -c main.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -g3 -c my_string.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -Wconversion -g3 -c unit_tests.c
gcc -o app.exe my_string.o unit_tests.o main.o