A token may have a higher precedence than it used to be

For example, the ‘+’ and the ‘-’ token

For a calculator, usually */ has higher precedence than +-

But, if +- are used as unary operator, i.e, -1, +2, it may have higher
precedence than */

The below example gives ‘+’ the highest precedence when ‘+’ is a
unary operator

The %prec directive gives
the rightmost token (terminal)
in the production
an equivalent
precedence to the
specified token

%left ‘+’
%left ‘*’
%nonassoc UPLUS
%%
E
: E ‘+’ E
| E ‘*’ E
| ‘+’ E %prec UPLUS


//變數使用前要先宣告(declaration)，C 的 extern 關鍵字，用來表示此變數已經在別處定義(definition)，告知程式到別的地方找尋此變數的定義(可能在同一個檔案或其他檔案)。
//。yylval的类型由YYSTYPE决定

int mi_size;
        mi_size = 1000;
        char* mi_s = malloc(mi_size);
        
        char mi_s2[6] = "hello"; //ori- size +1;
        assert(1); // if mi_a==false, end the program. Need #include<assert.h>
        strcpy(mi_s, "Test_String.  ");
        strcat(mi_s, "The_Second_String");
        strcmp(mi_s, "Hello World"); //<0: s1<s2, >0: s1>s2
    strlen(mi_s); // c_string size: try traverse
            
        char mi_c = 't';
        strchr(mi_s, mi_c); // find char c in str1, return its index. 
                         //If no found, return NULL.

        strrchr(mi_s, mi_c); //strchr_reverse
        strstr(mi_s, mi_s2); //find the index of substring mi_s2.
        int mi_i = atoi("1");      float mi_f = atof("1.2");    long mi_l = atol("123456789");