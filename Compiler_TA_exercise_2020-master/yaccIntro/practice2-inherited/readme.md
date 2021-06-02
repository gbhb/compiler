# Practice 2

Discription 
-----------
此練習為熟悉action，並了解Inherited的使用時機

分析的語法為：字串 字串 數字

.y file
-------
- line :test test integer  此production的action要輸出數字
- integer :INUMBER  此production的action要輸出數字前的兩個字串

.l file
-------
- [a-zA-Z]+  此rule的action把yytext的值丟給yylval


Input 
-----
`uuu ttt  123`

Output
------
`first: uuu second: ttt
123`

declaration
: class type namelist ;
class
: GLOBAL
{ $$ = 1; }
| LOCAL
{ $$ = 2; }
;
type
: REAL
{ $$ = 1; }
| INTEGER
{ $$ = 2; }
;
namelist
: NAME
{ mksymbol($0, $-1, $1); }

If default type is integer

mksymbol($0, $-1, $1)

If variable name for class and type is .class and .type, respectively

mksymbol($<type>0, $<class>-1, $1)