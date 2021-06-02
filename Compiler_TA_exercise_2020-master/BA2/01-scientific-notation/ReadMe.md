# Scientific Notation

## Description
Your task is to use Lex and regular expression to find out all the input lines that satisfy the definition of normalized scientific notation. Please print each line that satisfies the ormalized scientific notation with a newline character.If there is an input line doesn't satisfy the definition, then ignore it.

A scientific notation is made up by Normalized significand(m) and Exponentiation(n), where:
- Normalized significand m is any real number, that at least 1 but less than 10
= Exponentiation n is an integer


Here are some examples:
 3.14E159 -> Correct
 3.14E+159 -> Correct
 +3.14E159 -> Correct 

## Sample Input
  3.14E159
  3.14E+159
  +3.14E159
  +3.14E+159
  31.4E159 
  31.4E1.59
  31.4E+159
  31.4E-159
  +31.4E+159
  -31.4E-159

## Sample Output
  3.14E159
  3.14E+159
  +3.14E159
  +3.14E+159

## How to Run

```shell

$ make
$ cat ./scientific_notation filename.in

```
