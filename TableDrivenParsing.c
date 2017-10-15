#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <string.h>
#include "TableDrivenParsing.h"
#include "LinkedList.c"
#include "LinkedList.h"

typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftmostChild, rightSibling;
};

TREE parseTree;
char *nextTerminal;
int indentCounter = 0;
int tested = 0;

TREE makeNode0(char x){
    TREE root;
    root = (TREE)malloc(sizeof(struct NODE));
    root->label = x;
    root->leftmostChild = NULL;
    root->rightSibling = NULL;
    return root;
}
TREE makeNode1(char x, TREE t){
    TREE root;
    root = makeNode0(x);
    root->leftmostChild = t;
    return root;
}
TREE makeNode2(char x, TREE t1, TREE t2){
    TREE root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    return root;
}
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3){
    TREE root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    return root;
}
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4){
    TREE root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    t3->rightSibling = t4;
    return root;
}
void pre_order(TREE t) {
  if (t == NULL) {
    indentCounter--;
    return;
  } else {
    printf("\n");
    for(int i = 0; i<= indentCounter; i++){
      printf("  ");
    }
    if(t->label == 'B' || t->label == 'D' || t->label == 'N' ||
       t->label == 'I'){
      printf("<");
      printf("%c", t->label);
      printf(">");
    } else{
      printf("%c", t->label);
    }
    indentCounter++;
    pre_order(t->leftmostChild);
    pre_order(t->rightSibling);
  }
}

bool table_driven() {
  char* input = "3+5";
  printf("Input: %s\n", input);

  int productions[6][8] = {{1, 0, 0, 0, 0, 0, 1, 0},
                  {2, 0, 0, 0, 0, 0, 2, 0},
                  {0, 5, 3, 4, 0, 0, 0, 5},
                  {6, 0, 0, 0, 0, 0, 6, 0},
                  {0, 9, 9, 9, 7, 8, 0, 0},
                  {10, 0, 0, 0, 0, 0, 11, 0},
                };
  LinkedList *list = LinkedList_new();
  LinkedList_add_at_front(list, "S");

  for (int i = 0; input[i] != '\0'; i++) {
      if (input[i] == '0' || input[i] == '1' || input[i] == '2' ||
        input[i] == '3'|| input[i] == '4'|| input[i] == '5'||
        input[i] == '6'|| input[i] == '7'|| input[i] == '8'||
        input[i] == '9') {
          tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "S") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "Z");
              LinkedList_add_at_front(list, "E");
            }
            if (strcmp(LinkedList_element_at(list, 0), "E") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "J");
              LinkedList_add_at_front(list, "T");
            }
            if (strcmp(LinkedList_element_at(list, 0), "T") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "K");
              LinkedList_add_at_front(list, "F");
            }
            if (strcmp(LinkedList_element_at(list, 0), "F") == 0) {
              tested = 1;
              LinkedList_pop(list);
              if (input[i] == '0') {
                LinkedList_add_at_front(list, "0");
              } else if (input[i] == '1') {
                LinkedList_add_at_front(list, "1");
              } else if (input[i] == '2') {
                LinkedList_add_at_front(list, "2");
              } else if (input[i] == '3') {
                LinkedList_add_at_front(list, "3");
              } else if (input[i] == '4') {
                LinkedList_add_at_front(list, "4");
              } else if (input[i] == '5') {
                LinkedList_add_at_front(list, "5");
              } else if (input[i] == '6') {
                LinkedList_add_at_front(list, "6");
              } else if (input[i] == '7') {
                LinkedList_add_at_front(list, "7");
              } else if (input[i] == '8') {
                LinkedList_add_at_front(list, "8");
              } else if (input[i] == '9') {
                LinkedList_add_at_front(list, "9");
              }
            }
            if (tested == 0) {
              return false;
            }
          }
          LinkedList_print_string_list(list);
          char* p = LinkedList_pop(list);
          printf("Popped Element: %s", p);
      }
      if (input[i] == '(') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "S") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "Z");
              LinkedList_add_at_front(list, "E");
            }
            if (strcmp(LinkedList_element_at(list, 0), "E") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "J");
              LinkedList_add_at_front(list, "T");
            }
            if (strcmp(LinkedList_element_at(list, 0), "T") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "K");
              LinkedList_add_at_front(list, "F");
            }
            if (strcmp(LinkedList_element_at(list, 0), "F") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, ")");
              LinkedList_add_at_front(list, "E");
              LinkedList_add_at_front(list, "(");
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == ')') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "J") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == '+') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "J") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "J");
              LinkedList_add_at_front(list, "T");
              LinkedList_add_at_front(list, "+");
            }
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == '-') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "J") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "J");
              LinkedList_add_at_front(list, "T");
              LinkedList_add_at_front(list, "-");
            }
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == '*') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "K");
              LinkedList_add_at_front(list, "F");
              LinkedList_add_at_front(list, "*");
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == '/') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
              LinkedList_add_at_front(list, "K");
              LinkedList_add_at_front(list, "F");
              LinkedList_add_at_front(list, "/");
            }
            if (tested == 0) {
              return false;
            }
          }
      }
      if (input[i] == 'Z') {
        tested = 0;
          while(LinkedList_element_at(list, 0)[0] != input[i]) {
            if (strcmp(LinkedList_element_at(list, 0), "J") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (strcmp(LinkedList_element_at(list, 0), "K") == 0) {
              tested = 1;
              LinkedList_pop(list);
            }
            if (tested == 0) {
              return false;
            }
          }
      }
  }
  return !LinkedList_is_empty(list);
}

int main(int argc, char* argv[]) {
  int pass = table_driven();
  printf("Pass: %d", pass);

}
