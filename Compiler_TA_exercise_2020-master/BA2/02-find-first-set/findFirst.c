#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * 	1.in
 * 	---------------
        s abc
        a A|cB|;
        b c|Da|;
        c E|F|;
        END_OF_GRAMMAR

        1.out
        ---------------
        s FEDBA;
        c FE;
        b FED;
        a FEBA;
        END_OF_FIRST
*/
typedef struct node {
  // int val;
  struct node *next;
  char arr[20]; // the array to save CFG per line
} node_t;

char c, temp, nonTerminal;
int i = 0;
char nTmnl[10];
char firstSet[10];

int main(int argc, char *argv[]) {
  node_t *head = malloc(sizeof(node_t));
  node_t *current = malloc(sizeof(node_t));
  node_t *root = malloc(sizeof(node_t));
  head = current;

  FILE *fp;
  // char c, temp; int i=0; bool flag = true;
  fp = fopen(argv[1], "r");
  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      current->next = malloc(sizeof(node_t));
      // current->next->next = NULL;
      current = current->next;
      current->next = NULL;
      flag = true;
      i = 0;
    } else if (c == '>' || c == ' ') {
      continue;
    } else if (c == '|') {
      current->next = malloc(sizeof(node_t));
      current = current->next;
      i = 0;
      current->arr[i] = temp;
      i++;
      continue;
    } else {
      current->arr[i] = c;
      i++;
      current->next = NULL;
      if (flag) {
        temp = c;
        flag = false;
      }
    }
  }
  fclose(fp);
  root = head;

  printf("Enter the non-terminal to find first set of\n");
  scanf("%c", &nonTerminal);
  printf("The first set of %c: ", nonTerminal);
  first_set(root, nonTerminal);
  printf("\n----------------------\n");

  print_list(root);
}
char print_list(node_t *root) {
  while (root->next != NULL) {
    for (i = 0; i < 20; i++) {
      printf("%c", root->arr[i]);
    }
    printf("\n");
    root = root->next;
  }
  return 0;
}
char get_nTmal(node_t *root){

  return 0;
}
void arr_union(char *ptr, char c){
  	int flag = 0;
	while(ptr!=NULL){
		if(c = *ptr)	flag =1;
	}
	ptr++;
	
}
char first_set(node_t *root, char c) {
  node_t *shoot = root;
  while (shoot != NULL) {
    if (shoot->arr[0] == c) {
      int j = 1;
      while (shoot->arr[j]) {
        if (isupper(shoot->arr[j])) {
          printf("{%c}", shoot->arr[j]);
        } else if ((shoot->arr[j]) == ';') {
          printf("{%c}", shoot->arr[j]);
          break;
        } else {
          first_set(shoot, shoot->arr[j]);
        }
        j++;
      }
    }
    shoot = shoot->next;
  }
  return 0;
}
