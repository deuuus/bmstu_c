@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c -g3 main.c utilities.c
gcc -o app.exe main.o utilities.o