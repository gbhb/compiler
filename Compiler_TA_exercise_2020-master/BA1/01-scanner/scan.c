#include "data.h"
#include "decl.h"
#include "defs.h"
#include <string.h>

// Lexical scanning

// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

// Get the next character from the input file.
static int next(void) {
  int c;

  if (Putback) { // Use the character put
    c = Putback; // back if there is one
    Putback = 0;
    return c;
  }

  c = fgetc(Infile); // Read from input file
  if ('\n' == c)
    Line++; // Increment line count
  return c;
}

// Put back an unwanted character
static void putback(int c) { Putback = c; }

// Skip past input that we don't need to deal with,
// i.e. whitespace, newlines. Return the first
// character we do need to deal with.
static int skip(void) {
  int c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}

// Return the next character from a character
// or string literal
static int scanch(void) {
  int c;

  // Get the next input character and interpret
  // metacharacters that start with a backslash
  c = next();
  if (c == '\\') {
    switch (c = next()) {
    case 'a':
      return '\a';
    case 'b':
      return '\b';
    case 'f':
      return '\f';
    case 'n':
      return '\n';
    case 'r':
      return '\r';
    case 't':
      return '\t';
    case 'v':
      return '\v';
    case '\\':
      return '\\';
    case '"':
      return '"';
    case '\'':
      return '\'';
    default:
      printf("scnach debug");
    }
  }
  return (c); // Just an ordinary old character!
}

// Scan and return an integer literal
// value from the input file.

static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return (val);
}

// Scan in a string literal from the input file,
// and store it in buf[]. Return the length of
// the string.
static char *scanstr(char *buf) {
  int i, c;
  // Loop while we have enough buffer space
  buf[0] = '\"';
  for (i = 1; i < TEXTLEN - 1; i++) {
    // Get the next char and append to buf
    // Return when we hit the ending double quote
    if ((c = scanch()) == '"') {
      buf[i] = '\"';
      char *output = malloc(sizeof(char) * i);
      strncat(output, buf, i + 1);
      return (output);
    }
    buf[i] = c;
  }
  // Ran out of buf[] space
  printf("invalid input\n");
  exit(0);
}

// Scan an identifier from the input file and
// store it in buf[]. Return the identifier's length
static char *scanident(int c, char *buf, int lim) {
  int i = 0;
  // Allow digits, alpha and underscores
  while (isalpha(c) || isdigit(c) || '_' == c) {
    // Error if we hit the identifier length limit,
    // else append to buf[] and get next character
    if (lim - 1 == i) {
      printf("invalid input\n");
    } else if (i < lim - 1) {
      buf[i++] = c;
      // printf("%c\n",c);
    }
    c = next();
  }
  // We hit a non-valid character, put it back.
  // NUL-terminate the buf[] and return the length
  putback(c);
  buf[i] = '\0';

  char *output = malloc(sizeof(char) * i);
  strncat(output, buf, i + 1);
  // printf("%s\n",output);
  return (output);
}

// Scan and return an integer literal
// value from the input file. Store
// the value as a string in Text.
/*
static int (int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}
*/

// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.

int scan(struct token *t) {
  int c;
  char s;

  // Skip whitespace
  c = skip();

  // Determine the token based on
  // the input character
  switch (c) {
  case EOF:
    return (0);
  case '(':
    t->str = "(";
    t->token = T_LBR;
    break;
  case ')':
    t->str = ")";
    t->token = T_RBR;
    break;
  case '.':
    t->str = ".";
    t->token = T_DOT;
    break;
  case ';':
    t->str = ";";
    t->token = T_SEMICOLON;
    break;
  case '"':
    // Scan in a literal string
    t->str = scanstr(Text);
    // printf("%s\n", t->str);
    t->token = T_STRLIT;
    break;

  default:
    if (isdigit(c)) {
      scanint(c);
      t->str = "ERR";
      printf("invalid input\n");
      exit(1);
    } else if (isalpha(c) || '_' == c) {
      // Read in a keyword or identifier
      t->str = scanident(c, Text, TEXTLEN);
      t->token = T_ID;
      break;
    } else {
      // printf("Unrecognised character %c on line %d\n", c, Line);
      t->token = T_ERROR;
      printf("invalid input\n");
      exit(1);
    }


    return (1);
  }
}