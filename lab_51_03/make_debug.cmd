@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -g3 -c file_size.c func.c main.c
gcc -o app.exe file_size.o func.o main.o