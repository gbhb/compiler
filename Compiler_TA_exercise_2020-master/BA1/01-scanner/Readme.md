# **Scanner**

### **Description**

Token is the smallest unit in a compiler. Input text should be transformed into token by scanner first, then Parser can do the next step. Please write a scanner to get tokens by Table 1. and print it out.

**Input Format**

Input one line program source, each line will end with a &#39;\n&#39; character.

Not all input will follow the token definition.

### **Output Format**

If the program source follow the definition, print each token&#39;s type and the string of token seperated by a whitespace and end with a newline.

Otherwise print only &quot;invalid input&quot; with a newline even if there is just one wrong. (don&#39;t output any token!)

Table 1.

| **Terminal** | **Regular Expression** |
| --- | --- |
| ID | [A-Za-z\_][A-Za-z0-9\_]\* |
| STRLIT | &quot;[^&quot;]\*&quot; |
| LBR | \( |
| RBR | \) |
| DOT | \. |
| SEMICOLON | ; |

full description read ScannerTest_English.docx

In Sample Output2, although &quot;Str.length(&quot;123&quot;);&quot; can be cut by definition correctly, but there is no definition for &quot;1&quot;, so print &quot;invalid input&quot;.

In Sample Output3,&quot;STRLIT&quot; token should have two&quot; &quot; &quot;, there is no definition for only one &quot; &quot; &quot;, so print &quot;invalid input&quot;.

## Reference 

https://github.com/DoctorWkt/acwj/

forked from his project

## How to run code

```shell

$ make
cc -o scanner -g main.c scan.c

$ ./scanner filename.in

```
