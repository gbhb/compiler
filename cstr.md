1.gets函式使用
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main01()
{
char a[100];//hello wrold\n\0
//正規表示式
//scanf("%[^\n]", a);
//gets(a);
//在獲取鍵盤上的字元的時候會根據sizeof（）求出字串長度-1
//是為了接收換行操作，在字串讀取完成自後會將換行替換為\0
//fgets是一種安全的字串讀函式，更多用於檔案讀寫
fgets(a, sizeof(a), stdin);
printf("%s\n", a);
return 0;
}
2.puts函式的使用
#include <stdio.h>
#include <string.h>
int main02(void)
{
char arr[] = "hello\n\n\0\0 world";//16
unsigned int len = strlen(arr);
printf("%d%d", sizeof(arr), len);
printf("%s", arr);
puts(arr);//輸出字串並還行,等效於printf("%s\n",s)，前提 ：s是C風格字串，最後以'\0'結尾。
fputs(arr, stdout);
//fputs是一種函式，具有的功能是向指定的檔案寫入一個字串（不自動寫入字串結束標記符‘\0’）。
//成功寫入一個字串後，檔案的位置指標會自動後移，函式返回值為非負整數；
//否則返回EOF(符號常量，其值為-1)。
return 0;
}
03.strcpy函式的使用
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
char arr[] = "he你好llo\n wolrd";
char dest[100];
//目標字串 dest  源字串 arr
//拷貝字串內容是到第一個\0為止的所有字元
strcpy(dest, arr);
//有限拷貝  拷貝N個字元
//有限拷貝如果少於源字串不會自動加上\0
strncpy(dest, arr, 2);
strlen(dest);
dest[2] = 0;
printf("%s", dest);
puts(dest);
}
4.strcat函式的使用
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
char arr[] = "world";
char dest[12] = "hello";
strcat(dest, " ");
strcat(dest, arr);
//strncat(dest, arr, 2);
//只複製2個字元到目標
printf("%s", dest);
return 0;
}
5.strcmp函式的使用
#include <stdio.h>
#include <string.h>
int main(void)
{
//比較有效字串且長度相同比對ASCII碼
//返回值 第一個字串的ASCII值大於第二個字串的ASCII值1
//返回值 第一個字串的ASCII值小於第二個字串的ASCII值-1
//返回值 第一個字串的ASCII值相同第二個字串的ASCII值0
char arr[] = "oschina\0nihao";
char dest[] = "oschina\0nihao";
//會在編譯時對程式碼進行優化 
int a=0;
printf("%d\n", a);
int len = strcmp(dest, arr);
printf("%d\n",len);
if (!strcmp(dest, arr))
{
printf("兩個字串相同");
}
if (!strncmp(arr, dest, 3))//對比前3個字元
{
printf("兩個字串相同");
}
printf("%d\n", len);
return 0;
}
6.字串格式化
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
//適用於將字串內容儲存在一個檔案中
char *s = NULL;
sprintf(s, "%d", 123);//產生"123"可以指定款都，不足的時候左邊不空格
sprintf(s, "%8d%8d", 123, 4567); //產生：" 123 4567"當然也可以左對齊：
sprintf(s, "%-8d%8d", 123, 4567); //產生："123 4567"
//也可以按照16 進位制列印：
sprintf(s, "%8x", 4567); //小寫16 進位制，寬度佔8 個位置，右對齊
sprintf(s, "%-8X", 4568); //大寫16 進位制，寬度佔8 個位置，左對齊
sprintf(s, "%08X", 4567); //產生："000011D7"
sprintf(s, "%f", 3.1415926); //產生"3.141593"
/*但有時我們希望自己控制列印的寬度和小數位數，這時就應該使用："%m.nf"格式，其中m 表
示列印的寬度，n 表示小數點後的位數。比如：*/
sprintf(s, "%10.3f", 3.1415626); //產生：" 3.142"
sprintf(s, "%-10.3f", 3.1415626); //產生："3.142 "
sprintf(s, "%.3f", 3.1415626); //不指定總寬度，產生："3.142"
//連線字串  許多場合可以替代strcat，但sprintf 能夠一次連線多個字串
char* ss = "hello";
char*sss = "world";
sprintf(s, "%s  %s.", ss, sss); //產生："I love CSDN. "
//strcat 只能連線字串（一段以''結尾的字元陣列或叫做字元緩衝，null-terminated-string）
char a1[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
char a2[] = { 'H', 'I', 'J', 'K', 'L', 'M', 'N' };
sprintf(s, "%s%s", a1, a2);//GG
sprintf(s, "%7s%7s", a1, a2);//gg
sprintf(s, "%.7s%.7s", a1, a2);//產生："ABCDEFGHIJKLMN"
sprintf(s, "%.6s%.5s", a1, a2);//產生："ABCDEFHIJKL"
}
7.字串查詢
#include <stdio.h>
#include <string.h>
int main(void)
{
char arr[] = "helloworld";//arr[0] arr[1]
//查詢一個字元，在字串第一次出現的地址
//如果沒有找到相對於的字元，返回值為null
char *c;
if ((c = strchr(arr, 'w')) == NULL)
{
printf("查詢失敗！");
}
printf("%s\n", &arr[1]);
char arr1[] = "新建文字文件";
char arr2[] = "文件";
c = strstr(arr1, arr2);
//windowsclassname="新建文字文件"；
if ((c = strstr(arr1, arr2)) != NULL)
{
printf("%s\n", arr1);
}
printf("%s\n", c);
return 0;
}
8.字串擷取
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
//切割字串，將str切分成一個個子串
char arr[] = "www.oschina.net";
char *p = strtok(arr, ".");//從目標中，符合字元處開始擷取
//字串中每個字元都會 當作分割符
while (p != NULL)
{
printf("%s\n", p);
p = strtok(NULL, ".");
}
printf("%s\n", arr);
return 0;
}


9.字串轉化為其他類
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
char arr[] = "100";
int a = atoi(arr);//將字串轉化為int
float b = atof(arr);//將字串轉化為float
long c = atol(arr);//將字串轉化為long
sprintf(arr, "%d", 100);
printf("%d\n", c);
return 0;
}

10.
头文件：#include <string.h>

定义函数：char * strdup(const char *s);

函数说明：strdup()会先用maolloc()配置与参数s 字符串相同的空间大小，然后将参数s 字符串的内容复制到该内存地址，然后把该地址返回。该地址最后可以利用free()来释放。

返回值：返回一字符串指针，该指针指向复制后的新字符串地址。若返回NULL 表示内存不足。

范例
#include <string.h>
main(){
    char a[] = "strdup";
    char *b;
    b = strdup(a);
    printf("b[]=\"%s\"\n", b);
}

执行结果：
b[]="strdup"


字串相關
將字串轉成大寫
Example
#include <iostream>
#include <string.h>
#include <algorithm>
 
int main () {
  string method = "http";
  std::transform(method.begin(), method.end(), method.begin(), ::toupper);
}
將字串 string 轉成數字 int
string to int
string s = "1";
int a = atoi(s.c_str());
將字串串接 , sprintf
Example
char* buff = new char[200];
sprintf(buff , "%s.%s", a, b);
//  %# %s 接的值不能用 string ，需轉換 string.c_str()
Memory locate and free
有一次想用 C 語言寫個小功能，在寫程式的途中有用到一些字串的 buff，於是我定義了 char* buff = new char(12)，想說來個 12 bytes 的字串，最後再加一句 delete[] buff，來移除 memory，結果出錯了，錯誤訊息:「free(): invalid next size (fast)」，gcc 也算貼心了，幫你寫出問題，不過我看來看去，完全找不到任何邏輯有錯的地字，一直過了幾天，才發現小括號是直接給值的意思，不是分配記憶體呀!!! 所以我一直在指定 buff 這個變數等於字串(12)，總個超傻眼，正確的分配記憶體方式，請用中括號。

Example
//char* buff = new char(12) // wrong !
char* buff = new char[50];
delete[] buff
string to char
Example
char *res = new char[500];
    strcpy(resr, header.c_str());


const char* 裁字
如果我想擷取 bc 這兩個字。

Example
char* tx = (char*) malloc (sizeof(char) * 3);
const char* p = { "abcde" };
memcpy(tx, p + 1, 2);
*(tx + 2) = '\0';