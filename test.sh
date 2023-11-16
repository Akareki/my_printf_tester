make re
cc -w -c -I. */main.c -o main.o
cc -w main.o -L. libftprintf.a -o main
./main
