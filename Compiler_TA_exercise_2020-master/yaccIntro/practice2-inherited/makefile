CC = gcc
LEXYACC = practice2	
TARGET = practice2

all: practice2.l practice2.y 
	#compile bison
	bison -d -o y.tab.c practice2.y
	gcc -c -g -I.. y.tab.c 
	
	#compile flex
	flex -o lex.yy.c practice2.l	
	gcc -c -g -I.. lex.yy.c

	#compile and link bison and flex
	gcc -o practice2 y.tab.o lex.yy.o -ll

clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h *.o
