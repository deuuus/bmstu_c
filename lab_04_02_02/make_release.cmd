@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wvla -c main.c
gcc -std=c99 -Wall -Werror -Wvla -c get_words.c
gcc -std=c99 -Wall -Werror -Wvla -c check_pair.c
gcc -o app.exe check_pair.o get_words.o main.o