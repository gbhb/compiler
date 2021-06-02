本文中提到的函式庫有：<string> <cctype> <algorithm> <cmath> <cstdlib> <iomanip> <numeric>

1.   標準C++庫字串類std::string的用法

begin       得到指向字串開頭的Iterator
end         得到指向字串結尾的Iterator
rbegin      得到指向反向字串開頭的Iterator
rend        得到指向反向字串結尾的Iterator
size        得到字串的大小
length()    和size函式功能相同
max_size    字串可能的最大大小
capacity    在不重新分配記憶體的情況下，字串可能的大小
empty       判斷是否為空
operator[]  取第幾個元素，相當於陣列
c_str       取得C風格的const char* 字串
data        取得字串內容地址
operator=   賦值操作符
reserve     預留空間
swap        交換函式
insert      插入字元
append      追加字元
push_back   追加字元
erase       刪除字串
clear       清空字元容器中所有內容
resize      重新分配空間
assign      和賦值操作符一樣
replace     替代
copy        字串到空間
find        查詢,返回基於0的索引號
rfind       反向查詢

find_first_of        查詢包含子串中的任何字元，返回第一個位置
find_first_not_of    查詢不包含子串中的任何字元，返回第一個位置
find_last_of         查詢包含子串中的任何字元，返回最後一個位置
find_last_not_of     查詢不包含子串中的任何字元，返回最後一個位置
substr(n1,len)       得到字串從n1開始的長度為len的子串
compare              比較字串(支援所有的關係運算符)
operator+            字串連結
operator+=           += 操作符
operator==           判斷是否相等
operator!=           判斷是否不等於
operator<            判斷是否小於
operator>>           從輸入流中讀入字串
operator<<           字串寫入輸出流
getline              從輸入流中讀入一行

2.cctype庫

using ::isalpha; //是否字母

using ::iscntrl; //是否控制符

using ::isdigit; //是否是數字

using ::isgraph; //是否字母、數字或標點

using ::islower; //是否小寫

using ::isprint; //是否可列印字元

using ::ispunct; //是否標點

using ::isspace; //是否空格

using ::isupper; //是否大寫

using ::isxdigit; //是否十六進位制數字

using ::tolower; //轉為小寫

using ::toupper; //轉為大寫

3 algorithm.庫

迴圈

對序列中的每個元素執行某項操作

for_each()

查詢

在序列中找出某個值的第一次出現的位置

find(a,a+size,n) 返回b,當b=a+size即沒找到，a為指標

在序列中找出符合某謂詞的第一個元素

find_if()

在序列中找出一子序列的最後一次出現的位置

find_end()

在序列中找出第一次出現指定值集中之值位置

find_first_of()

在序列中找出相鄰的一對值

adjacent_find()

計數

在序列中統計某個值出現的次數

count()

在序列中統計與某謂詞匹配的次數

count_if()

比較

找出兩個序列相異的第一個元素

mismatch()

兩個序列中的對應元素都相同時為真

equal(a,a+n,b,cmp)

在序列中找到等於某值的連續n次出現的位置

equal_range(a,a+n,x)

搜尋

在序列中找出一子序列的第一次出現的位置

search()

在序列中找出一值的連續n次出現的位置

search_n()

複製

從序列的第一個元素起進行復制

copy()

從序列的最後一個元素起進行復制

copy_backward()

交換

交換兩個元素

swap()

交換指定範圍的元素

swap_ranges()

交換由迭代器所指的兩個元素

iter_swap()

變換

將某操作應用於指定範圍的每個元素

transform()

替換

用一個給定值替換一些值

replace()

替換滿足謂詞的一些元素

replace_if()

複製序列時用一給定值替換元素

replace_copy()

複製序列時替換滿足謂詞的元素

replace_copy_if()

填充

用一給定值取代所有元素

fill()

用一給定值取代前n個元素

fill_n()

生成

用一操作的結果取代所有元素

generate()

用一操作的結果取代前n個元素

generate_n()

刪除

刪除具有給定值的元素

remove()

刪除滿足謂詞的元素

remove_if()

複製序列時刪除具有給定值的元素

remove_copy()

複製序列時刪除滿足謂詞的元素

remove_copy_if()

唯一

刪除相鄰的重複元素

unique()

複製序列時刪除相鄰的重複元素

unique_copy()

反轉

反轉元素的次序

reverse(a,a+n)

複製序列時反轉元素的次序

reverse_copy()

環移

迴圈移動元素

rotate(a,a+m,a+n)

以m位置為界交換前後序列

複製序列時迴圈移動元素

rotate_copy()

隨機

採用均勻分佈來隨機移動元素

random_shuffle()

劃分

將滿足某謂詞的元素都放到前面

partition()

將滿足某謂詞的元素都放到前面並維持原順序

stable_partition()

排序

以很好的平均效率排序

sort(a,a+20,cmp)

bool cmp( int a, int b )

{ return a>b; }

在容器中或string用begin（）

排序，並維持相同元素的原有順序

stable_sort()

將序列的前一部分排好序

partial_sort()

複製的同時將序列的前一部分排好序

partial_sort_copy()

第n個元素

將第n各元素放到它的正確位置

nth_element()

二分檢索

找到大於等於某值的第一次出現

lower_bound()

找到大於某值的第一次出現

upper_bound()

找到（在不破壞順序的前提下）可插入給定值的最大範圍

equal_range()

在有序序列中確定給定元素是否存在

binary_search()

歸併

歸併兩個有序序列

merge()

歸併兩個接續的有序序列

inplace_merge()

有序結構上的集合操作

一序列為另一序列的子序列時為真

includes()

構造兩個集合的有序並集

set_union()

構造兩個集合的有序交集

set_intersection()

構造兩個集合的有序差集

set_difference()

構造兩個集合的有序對稱差集（並-交）

set_symmetric_difference()

堆操作

向堆中加入元素

push_heap()

從堆中彈出元素

pop_heap()

從序列構造堆

make_heap()

給堆排序

sort_heap()

最大和最小

兩個值中較小的

min()

兩個值中較大的

max()

序列中的最小元素

min_element(a,a+n)

序列中的最大元素

max_element()

詞典比較

兩個序列按字典序的第一個在前

lexicographical_compare()

排列生成器

按字典序的下一個排列

next_permutation()

按字典序的前一個排列

prev_permutation()

4 cmath庫

using ::abs; //絕對值

using ::acos; //反餘弦

using ::acosf; //反餘弦

using ::acosl; //反餘弦

using ::asin; //反正弦

using ::asinf; //反正弦

using ::asinl; //反正弦

using ::atan; //反正切

using ::atan2; //y/x的反正切

using ::atan2f; //y/x的反正切

using ::atan2l; //y/x的反正切

using ::atanf; //反正切

using ::atanl; //反正切

using ::ceil; //上取整

using ::ceilf; //上取整

using ::ceill; //上取整

using ::cos; //餘弦

using ::cosf; //餘弦

using ::cosh; //雙曲餘弦

using ::coshf; //雙曲餘弦

using ::coshl; //雙曲餘弦

using ::cosl; //餘弦

using ::exp; //指數值

using ::expf; //指數值

using ::expl; //指數值

using ::fabs; //絕對值

using ::fabsf; //絕對值

using ::fabsl; //絕對值

using ::floor; //下取整

using ::floorf; //下取整

using ::floorl; //下取整

using ::fmod; //求餘

using ::fmodf; //求餘

using ::fmodl; //求餘

using ::frexp; //返回value=x*2n中x的值,n存貯在eptr中

using ::frexpf; //返回value=x*2n中x的值,n存貯在eptr中

using ::frexpl; //返回value=x*2n中x的值,n存貯在eptr中

using ::ldexp; //返回value*2exp的值

using ::ldexpf; //返回value*2exp的值

using ::ldexpl; //返回value*2exp的值

using ::log; //對數

using ::log10; //對數

using ::log10f; //對數

using ::log10l; //對數

using ::logf; //對數

using ::logl; //對數

using ::modf; //將雙精度數value分解成尾數和階

using ::modff; //將雙精度數value分解成尾數和階

using ::modfl; //將雙精度數value分解成尾數和階

using ::pow; //計算冪

using ::powf; //計算冪

using ::powl; //計算冪

using ::sin; //正弦

using ::sinf; //正弦

using ::sinh; //雙曲正弦

using ::sinhf; //雙曲正弦

using ::sinhl; //雙曲正弦

using ::sinl; //正弦

using ::sqrt; //開方

using ::sqrtf; //開方

using ::sqrtl; //開方

using ::tan; //正切

using ::tanf; //正切

using ::tanh; //雙曲正切

using ::tanhf; //雙曲正切

using ::tanhl; //雙曲正切

using ::tanl; //正切

5.cstdlib庫

double atof(const char *str);

把字串str轉換成double型別。等價於：strtod(str, (char**)NULL)。

int atoi(const char *str);

把字串str轉換成int型別。等價於：(int)strtol(str, (char**)NULL, 10)。

long atol(const char *str);

把字串str轉換成long型別。等價於：strtol(str, (char**)NULL, 10)。

double strtod(const char *start, char **end);

把字串start的字首轉換成double型別。在轉換中跳過start的前導空白符，然後逐個讀入構成數的字元，任何非浮點數成分的字元都會終止上述過程。如果end不為NULL，則把未轉換部分的指標儲存在*end中。

如果結果上溢，返回帶有適當符號的HUGE_VAL，如果結果下溢，那麼函式返回0。在這兩種情況下，errno均被置為ERANGE。

long int strtol(const char *start, char **end, int radix);

把字串start的字首轉換成long型別，在轉換中跳過start的前導空白符。如果end不為NULL，則把未轉換部分的指標儲存在*end中。

如果radix的值在2到36間之間，那麼轉換按該基數進行；如果radix為0，則基數為八進位制、十進位制、十六進位制，以0為前導的是八進位制，以0x或0X為前導的是十六進位制。無論在哪種情況下，串中的字母是表示10到radix-1之間數字的字母。如果radix是16，可以加上前導0x或0X。

如果結果上溢，則依據結果的符號返回LONG_MAX或LONG_MIN，置errno為ERANGE。

unsigned long int strtoul(const char *start, char **end, int radix);

與strtol()類似，只是結果為unsigned long型別，溢位時值為ULONG_MAX。

int rand(void);

產生一個0到RAND_MAX之間的偽隨機整數。RAND_MAX值至少為32767。

void srand(unsigned int seed);

設定新的偽隨機數序列的種子為seed。種子的初值為1。

void *calloc(size_t num, size_t size);

為num個大小為size的物件組成的陣列分配足夠的記憶體，並返回指向所分配區域的第一個位元組的指標；如果記憶體不足以滿足要求，則返回NULL。

分配的記憶體區域中的所有位被初始化為0。

void *malloc(size_t size);

為大小為size的物件分配足夠的記憶體，並返回指向所分配區域的第一個位元組的指標；如果記憶體不足以滿足要求，則返回NULL。

不對分配的記憶體區域進行初始化。

void *realloc(void *ptr, size_t size);

將ptr指向的記憶體區域的大小改為size個位元組。如果新分配的記憶體比原記憶體大，那麼原記憶體的內容保持不變，增加的空間不進行初始化。如果新分配的記憶體比原記憶體小，那麼新記憶體保持原記憶體區中前size位元組的內容。函式返回指向新分配空間的指標。如果不能滿足要求，則返回NULL，原ptr指向的記憶體區域保持不變。

如果ptr為NULL，則行為等價於malloc(size)。

如果size為0，則行為等價於free(ptr)。

void free(void *ptr);

釋放ptr指向的記憶體空間，若ptr為NULL，則什麼也不做。ptr必須指向先前用動態分配函式malloc、realloc或calloc分配的空間。

void abort(void);

使程式非正常終止。其功能類似於raise(SIGABRT)。

void exit(int status);

使程式正常終止。atexit函式以與註冊相反的順序被呼叫，所有開啟的檔案被重新整理，所有開啟的流被關閉。status的值如何被返回依具體的實現而定，但用0表示正常終止，也可用值EXIT_SUCCESS和EXIT_FAILURE。

int atexit(void (*func)(void));

註冊在程式正常終止時所要呼叫的函式func。如果成功註冊，則函式返回0值，否則返回非0值。

int system(const char *str);

把字串str傳送給執行環境。如果str為NULL，那麼在存在命令處理程式時，返回0值。如果str的值非NULL，則返回值與具體的實現有關。

char *getenv(const char *name);

返回與name相關的環境字串。如果該字串不存在，則返回NULL。其細節與具體的實現有關。

void *bsearch(const void *key, const void *base, size_t n, size_t size,

int (*compare)(const void *, const void *));

在base[0]...base[n-1]之間查詢與*key匹配的項。size指出每個元素佔有的位元組數。函式返回一個指向匹配項的指標，若不存在匹配則返回NULL。

函式指標compare指向的函式把關鍵字key和陣列元素比較，比較函式的形式為：

int func_name(const void *arg1, const void *arg2);

arg1是key指標，arg2是陣列元素指標。

返回值必須如下：

arg1 < arg2時，返回值<0；

arg1 == arg2時，返回值==0；

arg1 > arg2時，返回值>0。

陣列base必須按升序排列(與compare函式定義的大小次序一致)。

void qsort(void *base, size_t n, size_t size,

int (*compare)(const void *, const void *));

對由n個大小為size的物件構成的陣列base進行升序排序。

比較函式compare的形式如下：

int func_name(const void *arg1, const voie *arg2);

其返回值必須如下所示：

arg1 < arg2，返回值<0；

arg1 == arg2，返回值==0；

arg1 > arg2，返回值>0。

int abs(int num);

返回int變元num的絕對值。

long labs(long int num);

返回long型別變元num的絕對值。

div_t div(int numerator, int denominator);

返回numerator/denominator的商和餘數，結果分別儲存在結構型別div_t的兩個int成員quot和rem中。

ldiv_t div(long int numerator, long int denominator);

返回numerator/denominator的商和餘數，結果分別儲存在結構型別ldiv_t的兩個long成員quot和rem中。

6.iomanip庫

dec 置基數為10 相當於"%d"

hex 置基數為16 相當於"%X"

oct 置基數為8 相當於"%o"

setfill( 'c' ) 設填充字元為c

setprecision( n ) 設顯示小數精度為n位

setw( n ) 設域寬為n個字元

▲setw(n)用法： 通俗地講就是預設寬度

這個控制符的意思是保證輸出寬度為n。如：

cout << setw( 3 ) << 1 << setw( 3 ) << 10 << setw( 3 ) << 100 <<setw(3)<<1000<< endl;

結果為:

(空格)(空格）1(空格)101001000

（預設是右對齊）當輸出長度大於3時(<<1000)，setw(3)不起作用。

▲setfill(char c) 用法 : 就是在預設寬度中如果已存在沒用完的寬度大小，則用設定的字元c填充

如 cout<<setfill(‘@‘)<<setw(5)<<255<<endl;

結果是:

@@255

▲setbase(int n) : 將數字轉換為 n 進位制.

如 cout<<setbase(8)<<setw(5)<<255<<endl;

cout<<setbase(10)<<setw(5)<<255<<endl;

cout<<setbase(16)<<255<<endl;

結果是:

(空格)（空格)377

(空格)(空格) 255

(空格)(空格) f f

▲ setprecision用法

使用setprecision(n)可控制輸出流顯示浮點數的數字個數。C++預設的流輸出數值有效位是6。

如果setprecision(n)與setiosflags(ios::fixed)合用，可以控制小數點右邊的數字個數。setiosflags(ios::fixed)是用定點方式表示實數。

如果與setiosnags(ios::scientific)合用，可以控制指數表示法的小數位數。setiosflags(ios::scientific)是用指數方式表示實數。

setiosflags(ios::fixed) 固定的浮點顯示

setiosflags(ios::scientific) 指數表示

setiosflags(ios::left) 左對齊

setiosflags(ios::right) 右對齊

setiosflags(ios::skipws) 忽略前導空白

setiosflags(ios::uppercase) 16進位制數大寫輸出

setiosflags(ios::lowercase) 16進位制小寫輸出

setiosflags(ios::showpoint) 強制顯示小數點

setiosflags(ios::showpos) 強制顯示符號

7.numeric庫

accumulate（first ，last，n）;

求和，n為初始值；

adjacent_difference（first，last，result）;

求相鄰元素的差，後減前，result為差的序列在原序列開始的位置

checked_ adjacent_difference(first,last,result);

inner_product(first1,first2,last1,last2);

將對應元素相乘並求出累計和

partial_sum（first，last，result）;

求到任意位置的累計和，result為和的序列在原序列開始的位置