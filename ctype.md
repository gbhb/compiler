 字元測試函數

【格式】：	int isalnum(int c);
【說明】：	測試c是否為alphabet(英文字母)或number(數字字母)，若兩者之一就傳回1(true)，否則傳回0(false)。表示方式： isalnum('A')或isalnum(65)。
【格式】：	int isalpha(int c);
【說明】：	測試c是否為alphabet(英文字母)，若是就傳回1，否則傳回0
【格式】：	int isascii(int c);
【說明】：	測試c是否為ASCII標準字元，若是就傳回1，否則傳回0，在目前IBM PC之ASCII內以此函數來測試只有內碼在0-127才是屬於ASCII標準字元，128-255之字元為擴充ASCII字元
【格式】：	int iscntrl(int c);
【說明】：	測試c是否為控制(contril)字元，若是就傳回1，否則傳回0，所謂控制字元其內碼在0-31及127等共33個，像Enter、tab、space等都是屬於此字元之範圍
【格式】：	int isdigit(int c);
【說明】：	測試c是否為阿拉伯數字字元'0'-'9'，若是就傳回1，否則傳回0
【格式】：	int ispunct(int c);
【說明】：	測試c是否為特殊符號字元(punctuation character)，若是就傳回1，否則傳回0，但不包括文數字與空白字元
【格式】：	int isgraph(int c);
【說明】：	測試c是否為可顯示字元，若是就傳回1，否則傳回0，一共有94個，包括英文字母52、數字10及特殊符號32個
【格式】：	int isprint(int c);
【說明】：	測試c是否為可列印字元，若是就傳回1，否則傳回0，一共有95個，包括空白字元1、英文字母52、數字10及特殊符號32個
【格式】：	int isspace(int c);
【說明】：	測試c是否歸納為空白字元，若是就傳回1，否則傳回0，一共有6個，內碼分別為9、10、11、12、13、32
【格式】：	int islower(int c);
【說明】：	測試c是否英文字母小寫字元(lowercase character)，若是就傳回1，否則傳回0，一共有26個
【格式】：	int isupper(int c);
【說明】：	測試c是否英文字母大寫字元(uppercase character)，若是就傳回1，否則傳回0，一共有26個
【格式】：	int isxdigit(int c);
【說明】：	測試c是否16進位字元(hexadecimal character)，若是就傳回1，否則傳回0，一共有22個，即0，1，2，3，4，5，6，7，8，9，a，b，c，d，e，f，A，B，C，D，E，F
 字元轉換函數

【格式】：	int toascii(int c);
【說明】：	將整數c之最低7位元轉為相對應之ASCII字元，其內碼範圍在0到127之間，若要轉為字元需作型態轉換(Type casting)，即在函數前加上char。例如：c=65，則toascii( c) = 65，char(toascii(c))='A'。
【格式】：	int tolower(int ch);
【說明】：	將字母ch之字元轉為小寫字母，若非小寫字母則保留原狀
【格式】：	int toupper(int ch);
【說明】：	將字母ch之字元轉為大寫字母，若非大寫字母則保留原狀
【格式】：	int _tolower(int ch);
【說明】：	將字母ch之字元轉為小寫字母，但必需確認ch是在'a'-'z'範圍內
【格式】：	int _toupper(int ch);
【說明】：	將字母ch之字元轉為大寫字母，但必需確認ch是在'A'-'Z'範圍內