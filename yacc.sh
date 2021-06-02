#!/bin/bash
if (("$#" < 2)) || (("$#" > 3)); then
    echo "Illegal number of arguments"
    exit 1
fi
bison -v -d -o "a.tab.c" $2
gcc -c -g -I.. "a.tab.c"
flex -o lex.yy.c $1
gcc -c -g -I.. lex.yy.c
if [ "$#" -eq 2 ]; then
    gcc -o a.out "a.tab.o" lex.yy.o -ll
elif [ "$#" -eq 3 ]; then
    gcc -o $3 "a.tab.o" lex.yy.o -ll
fi
