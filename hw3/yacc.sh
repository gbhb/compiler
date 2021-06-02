#!/bin/bash
if (("$#" < 2)) || (("$#" > 3)); then
    echo "Illegal number of arguments"
    exit 1
fi
bison -v -d -o "y.tab.c" $2
gcc -c -g -I.. "y.tab.c"
flex -o lex.yy.c $1
gcc -c -g -I.. lex.yy.c
if [ "$#" -eq 2 ]; then
    gcc -o a.out "y.tab.o" lex.yy.o -ll
elif [ "$#" -eq 3 ]; then
    gcc -o $3 "y.tab.o" lex.yy.o -ll
fi
