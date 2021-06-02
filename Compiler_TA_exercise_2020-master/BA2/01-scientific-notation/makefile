

all: scientific_notation.l
	flex scientific_notation.l
	gcc -o scientific_notation lex.yy.c -lfl

clear: 
	rm scientific_notation
