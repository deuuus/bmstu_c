@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wvla -c main.c
gcc -std=c99 -Wall -Werror -Wvla -c get_words.c
gcc -std=c99 -Wall -Werror -Wvla -c get_new_string.c
gcc -o app.exe get_new_string.o get_words.o main.o