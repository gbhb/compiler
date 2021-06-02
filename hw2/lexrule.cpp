//yytext[strlen(yytext)-1]='\0';printf("%s is a word\n",yytext);

// Metacharacter	Matches
// .	any character except newline	除換行以外的任何型別
// \n	newline	新行
// *	zero or more copies of the preceding expression	零或多個複製前面的表達式
// +	one or more copies of the preceding expression	一或多個複製前面的表達式
// ?	zero or one copy of the preceding expression	零或一個複製前面的表達式
// ^	beginning of line	起始行
// $	end of line	結束行
// a|b	a or b	a或b
// (ab)+	one or more copies of ab (grouping)	一或多個複製ab（合併）
// "a+b"	literal “a+b” (C escapes still work)	文字”a+b”  這句我看不懂Orz

// Expression	Matches	酷喔！用表情符號超方便！
// abc	abc	XD  XD
// abc*	ab abc abcc abccc ...	XD* X, XD, XDD, XDDD… (可以少c)
// abc+	abc, abcc, abccc, abcccc, ...	Orz+ Orz, Orzz, Orzzz, Orzzz…(不可少c)
// a(bc)+	abc, abcbc, abcbcbc, ...	O(rz)+ Orz,Orzrz, Orzrzrz (後面兩個重複)
// a(bc)?	a, abc	O(rz)? O, Orz (意思是有bc或沒bc二選一)
// [abc]	one of: a, b, c	[Orz]O, r, z 其中一個
// [a-z]	any letter, a through z	比對英文字母a~z
// [a\-z]	one of: a, -, z	比對a,-,z三者之一（加一個右斜線差很多！）
// [-az]	one of: - a z	比對-,a,z三者之一
// [A-Za-z0-9]+	one or more alphanumeric characters	一個或多個英文與數字
// [ \t\n]+	whitespace	白鍵
// [^ab]	anything except: a, b	任何值，除了a,b之外（所以可以用來去括號囉！？）
// [a^b]	a, ^, b	意思是將^放到中間以後，會當作符號來判別。
// [a|b]	a, |, b	將｜放在[ ] 類別中，會被當作符號來判別。
// a|b	a, b	將｜直接使用，則代表兩者。

// []
// Matches a character listed in brackets. If the first character is a
// circumflex (^), it inverses the meaning to match a not listed
// character. This is also called a character class.
// [abc] -> a, b, c [_a-z] -> a, b, …, z [^abc] -> 非a, b, c

// \
// The escape character.
// \. -> .

// {}
// Indicate how many times the preceding pattern is allowed to match.
// {times-lower-bound[,times-upper-bound]}
// ok{2} -> okok ok{2,} -> okokok ok{2,3} -> okokok

// 數字：^[0-9]*$
// n位定長的數字：^\d{n}$
// m-n位之間的數字：^\d{m,n}$
// 零和非零開頭的數字：^(0|[1-9][0-9]*)$
// 非零開頭的最多帶兩位小數的數字：^([1-9][0-9]*)+(.[0-9]{1,2})"color: #0000ff">字符相關的正則表達式

// 漢字：^[\u4e00-\u9fa5]{0,}$
// 長度為3-20的所有字符：^.{3,20}$
// 由數字和26個英文字母組成的字符串：^[A-Za-z0-9]+$
// 由數字、26個英文字母或者下劃線組成的字符串：^\w+$ 或 ^\w{3,20}$
// 中文、英文、數字包括下劃線：^[\u4E00-\u9FA5A-Za-z0-9_]+$
// 中文、英文、數字但不包括下劃線等符號：^[\u4E00-\u9FA5A-Za-z0-9]+$ 或 ^[\u4E00-\u9FA5A-Za-z0-9]{2,20}$
// 帳號是否合法(字母開頭，允許5-16字節，允許字母數字下劃線)：^[a-zA-Z][a-zA-Z0-9_]{4,15}$
// 密碼(以字母開頭，長度在6~18之間，只能包含字母、數字和下劃線)：^[a-zA-Z]\w{5,17}$
// 強密碼(必須包含大小寫字母和數字的組合，不能使用特殊字符，長度在8-10之間)：^("color: #0000ff">固定格式約定俗成的正則表達式

// Email地址：^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$
// 網站域名：[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(/.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+/.?
// URL網址：^http://([\w-]+\.)+[\w-]+(/[\w-./?%&=]*)?$
// 手機號碼：^(13[0-9]|17[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$
// 電話號碼(“XXX-XXXXXXX”、”XXXX-XXXXXXXX”、”XXX-XXXXXXX”、”XXX-XXXXXXXX”、”XXXXXXX”和”XXXXXXXX)：^(\(\d{3,4}-)|\d{3.4}-)?\d{7,8}$
// 國內電話號碼(0511-4405222、021-87888822)：\d{3}-\d{8}|\d{4}-\d{7}
// 身份證號(15位、18位數字)：^\d{15}|\d{18}$
// 日期格式：^\d{4}-\d{1,2}-\d{1,2}
// 一年的12個月(01～09和1～12)：^(0?[1-9]|1[0-2])$
// 一個月的31天(01～09和1～31)：^((0?[1-9])|((1|2)[0-9])|30|31)$
// 騰訊QQ號：[1-9][0-9]{4,8} (騰訊QQ號從10000開始，目前最長為10位)
// 中國郵政編碼：[1-9]\d{5}(?!\d) (中國郵政編碼為6位數字)
// IP地址：\d+\.\d+\.\d+\.\d+ (提取IP地址時有用)
// IP地址：((?:(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d)\\.){3}(?:25[0-5]|2[0-4]\\d|[01]?\\d?\\d))