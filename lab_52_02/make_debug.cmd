@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c main.c  file_size.c func.c
gcc -o app.exe file_size.o func.o main.o