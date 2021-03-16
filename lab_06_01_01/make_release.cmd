@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c utilities.c
gcc -o app.exe main.o utilities.o