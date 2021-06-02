#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include <errno.h>

#include "decl.h"

// Compiler setup and top-level execution
// Copyright (c) 2019 Warren Toomey, GPL3

// Compiler setup and top-level execution
// Copyright (c) 2019 Warren Toomey, GPL3

// Initialise global variables
int is_expr(void);

static void init() {
  Line = 1;
  Putback = '\n';
}

// Print out a usage if started incorrectly
static void usage(char *prog) {
  fprintf(stderr, "Usage: %s infile\n", prog);
  exit(1);
}

// List of printable tokens
char *tokstr[] = {"ID", "STRLIT", "LBR", "RBR", "DOT", "SEMICOLON", "T_INTLIT"};

int is_primary_tail(void){
  int a=0, b=0, c=0;
  switch (Token.token)
  {
  case (T_DOT):
    scan(&Token);
    // printf("%s %s\n", tokstr[Token.token], Token.str);
	a = (Token.token == T_ID)? 1:0;
    scan(&Token);
    // printf("%s %s\n", tokstr[Token.token], Token.str);
    b = is_primary_tail();
    if(a&&b) return 1;
    else return 0;
    break;
  case (T_LBR):
    scan(&Token);
    a = is_expr();
    // printf("%s %s a=%d\n", tokstr[Token.token], Token.str,a);
    scan(&Token);
    b = (Token.token == T_RBR)? 1:0;
    // printf("%s %s b=%d\n", tokstr[Token.token], Token.str,b);
    scan(&Token);
    c = is_primary_tail();
    // printf("%s %s c=%d\n", tokstr[Token.token], Token.str,c);
    if ((a&&b&&c)==1) return 1;
    else return 0;
    break;
  case (T_SEMICOLON):
    Line++;
    scan(&Token);
    //printf("%s %s\n", tokstr[Token.token], Token.str);
    return 1;
    break;
  default:
    return 0;
    break;
  }

}

int is_expr(void){
  switch (Token.token)
  {
  case (T_STRLIT):
    scan(&Token);
    //printf("%s %s\n", tokstr[Token.token], Token.str);
    return 1;
    break;
  case (T_ID):
    scan(&Token);
    //printf("%s %s\n", tokstr[Token.token], Token.str);
    return is_primary_tail();
    break;
  case (T_SEMICOLON):
    Line++;
    scan(&Token);
    //printf("%s %s\n", tokstr[Token.token], Token.str);
    return 1;
    break;
  default:
    return 0;
    break;
  }
  
}

  // Loop scanning in all the tokens in the input file.
  // Print out details of each token found.
  static void scanfile() {
    struct token T;
    while (scan(&T)) {
      printf("%s %s", tokstr[T.token], T.str);
      if (T.token == T_ERROR)
        printf("ERROR");
      printf("\n");
    }
  }
  static void parser() {
    while(scan(&Token)){
      // printf("%s %s\n", tokstr[Token.token], Token.str);
      if(is_expr() == 0){
        printf("Invalid Input\n");
        exit(0);
      }
    }
    printf("Valid Input\n");
  }
  // Main program: check arguments and print a usage
  // if we don't have an argument. Open up the input
  // file and call scanfile() to scan the tokens in it.
  void main(int argc, char *argv[]) {
    if (argc != 2)
      usage(argv[0]);

    init();

    if ((Infile = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
      exit(1);
    }
    /*
      // Create the output file
      // But not needed for this homework

    if ((Outfile = fopen("out.s", "w")) == NULL) {
      fprintf(stderr, "Unable to create out.s: %s\n", strerror(errno));
      exit(1);
    }
    */
    parser();

    // fclose(Outfile);		// Close the output file and exit
    exit(0);
  }
