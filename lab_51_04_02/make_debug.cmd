@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main.c get_between_average.c get_max_min.c -g3 -o app.exe