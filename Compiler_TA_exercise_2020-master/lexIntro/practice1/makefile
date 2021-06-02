
all:wordcount.l 
	flex wordcount.l 
	gcc -o wordcount lex.yy.c -lfl

clean: 
	rm -f wordcount

