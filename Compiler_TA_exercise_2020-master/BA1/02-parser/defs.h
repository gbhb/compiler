#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTLEN 512 // Length of symbols in input

// Tokens Types
enum { T_ID, T_STRLIT, T_LBR, T_RBR, T_DOT, T_SEMICOLON, T_ERROR };

// Token structure
struct token {
  int token;
  char *str;
};

