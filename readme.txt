chmod u+x yacc.sh
'/home/user/Desktop/new/yacc.sh' b.l b.y b



bison -d b.y -o b.tab.c
gcc -c -g -I.. b.tab.c

flex -o b.yy.c b.l
gcc -c -g -I.. b.yy.c
gcc -o b b.tab.o b.yy.o -ll

y.tab.h >> b.tab.h

sudo mount -t vboxsf "compiler" "/home/user/Desktop/new"
user