@ECHO OFF
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main.c process.c -g3 -o app.exe