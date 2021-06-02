%{
%}
%option noyywrap

Soul_Punch      dds|aas
Uppercut        `ws
Skull_Blast     `ds+
Mirror_Image    `tst+
Soul_Bomb       `dt
Big_Bang        `wt
%%
{Soul_Punch}      {printf("%s\n","Soul_Punch");}
{Uppercut}        {printf("%s\n","Uppercut");}
{Skull_Blast}     {printf("%s\n","Skull_Blast");}
{Mirror_Image}    {printf("%s\n","Mirror_Image");}
{Soul_Bomb}       {printf("%s\n","Soul_Bomb");}
{Big_Bang}        {printf("%s\n","Big_Bang");}
.|\n            ;
%%
int main(){
    yylex();
    return (0);
}