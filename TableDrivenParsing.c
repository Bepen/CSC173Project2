#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <string.h>
#include "TableDrivenParsing.h"
#include "Stack.c"
#include "Stack.h"

/*
typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftmostChild, rightSibling;
};
TREE parseTree;
int indentCounter = 0;
*/
int tested = 0;

/*
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
*/
/*
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
*/

//Parser for a table driven implementation of an input
bool table_driven(char* input) {
  printf("Input: %s\n", input);
  Stack *stack = Stack_new();
  Stack_add_at_front(stack, "S");
  parseTree = makeNode0('S');

  for (int i = 0; input[i] != '\0'; i++) {
      if (input[i] == '0' || input[i] == '1' || input[i] == '2' ||
        input[i] == '3'|| input[i] == '4'|| input[i] == '5'||
        input[i] == '6'|| input[i] == '7'|| input[i] == '8'||
        input[i] == '9') {
          //printf("Looking at: %c using the integers\n", input[i]);
          tested = 0;
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "S") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "Z");
              Stack_add_at_front(stack, "E");
            }
            if (strcmp(Stack_element_at(stack, 0), "E") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "J");
              Stack_add_at_front(stack, "T");
            }
            if (strcmp(Stack_element_at(stack, 0), "T") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "K");
              Stack_add_at_front(stack, "F");
            }
            if (strcmp(Stack_element_at(stack, 0), "F") == 0) {
              tested = 1;
              Stack_pop(stack);
              if (input[i] == '0') {
                Stack_add_at_front(stack, "0");
              } else if (input[i] == '1') {
                Stack_add_at_front(stack, "1");
              } else if (input[i] == '2') {
                Stack_add_at_front(stack, "2");
              } else if (input[i] == '3') {
                Stack_add_at_front(stack, "3");
              } else if (input[i] == '4') {
                Stack_add_at_front(stack, "4");
              } else if (input[i] == '5') {
                Stack_add_at_front(stack, "5");
              } else if (input[i] == '6') {
                Stack_add_at_front(stack, "6");
              } else if (input[i] == '7') {
                Stack_add_at_front(stack, "7");
              } else if (input[i] == '8') {
                Stack_add_at_front(stack, "8");
              } else if (input[i] == '9') {
                Stack_add_at_front(stack, "9");
              }
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //Input for left parenthesis
      if (input[i] == '(') {
        //printf("Looking at: %c with open parentheses\n", input[i]);
        tested = 0;
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "S") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "Z");
              Stack_add_at_front(stack, "E");
            }
            if (strcmp(Stack_element_at(stack, 0), "E") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "J");
              Stack_add_at_front(stack, "T");
            }
            if (strcmp(Stack_element_at(stack, 0), "T") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "K");
              Stack_add_at_front(stack, "F");
            }
            if (strcmp(Stack_element_at(stack, 0), "F") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, ")");
              Stack_add_at_front(stack, "E");
              Stack_add_at_front(stack, "(");
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //Parse row for left parenthesis
      if (input[i] == ')') {
        tested = 0;
        //printf("Looking at: %c with closed parentheses\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "J") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //Parse row for addition
      if (input[i] == '+') {
        tested = 0;
        //printf("Looking at: %c with the plus symbol\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "J") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "J");
              Stack_add_at_front(stack, "T");
              Stack_add_at_front(stack, "+");
            }
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }

      //Parse row for subtraction
      if (input[i] == '-') {
        tested = 0;
        //printf("Looking at: %c with the subtraction symbol\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "J") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "J");
              Stack_add_at_front(stack, "T");
              Stack_add_at_front(stack, "-");
            }
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //This is the parse tow for the multipliction
      if (input[i] == '*') {
        tested = 0;
        //printf("Looking at: %c with the multiplication symbol\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "K");
              Stack_add_at_front(stack, "F");
              Stack_add_at_front(stack, "*");
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //This is the parse row for the division symbol
      if (input[i] == '/') {
        tested = 0;
        //printf("Looking at: %c with the division symbol\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
              Stack_add_at_front(stack, "K");
              Stack_add_at_front(stack, "F");
              Stack_add_at_front(stack, "/");
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
      //This is the parse row for the end token
      if (input[i] == 'Z') {
        tested = 0;
        //printf("Looking at: %c with the end symbol\n", input[i]);
          while(Stack_element_at(stack, 0)[0] != input[i]) {
            if (strcmp(Stack_element_at(stack, 0), "J") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (strcmp(Stack_element_at(stack, 0), "K") == 0) {
              tested = 1;
              Stack_pop(stack);
            }
            if (tested == 0) {
              return false;
            }
          }
          //Stack_print_string_stack(stack);
          char* p = Stack_pop(stack);
          //printf("Popped Element: %s", p);
      }
  }
  //printf("\nStack: ");
  //Stack_print_string_stack(stack);
  //printf("Stack with epsilons\n");
  //These are the end syntactic category as well as the empty string categories and empties them.
  while (!Stack_is_empty(stack)) {
    if (strcmp(Stack_element_at(stack, 0), "Z") == 0
    || strcmp(Stack_element_at(stack, 0), "J") == 0
    || strcmp(Stack_element_at(stack, 0), "K") == 0) {
      Stack_pop(stack);
    } else {
      return false;
    }
  }
  //printf("\nStack: ");
  //Stack_print_string_stack(stack);
  return Stack_is_empty(stack);
}

//Loops until the user says to stop.
//Evaluates the table driven parser
void runTDP(){
  printf("\n");
  printf("Welcome to the Table Driven Parser. \n");
  printf("\n");
  printf("When entering expressions, please do not include spaces. \n");
  printf("Valid characters include: (, ), *, /, +, -, and all numbers. \n");
  printf("Warning, cannot include a digit followed by an parenthesis. \n");
  printf("Ex: cannot do 2(3+1), instead do 2*(3+1). \n");
  char *quitProg = malloc(64*sizeof(char));
  char *expression = malloc(64*sizeof(char));

  while(strncmp(quitProg, "no", 3) != 0){
    if(strncmp(quitProg, "no", 3) != 0){
      printf("Enter an expression: ");
      scanf("%s", expression);
      printf("\n");
      int pass = table_driven(expression);
      if (pass == 1) {
        printf("Passed.\n");
        //pre_order(parseTree);
      } else {
        printf("Failed.\n");
      }
      printf("\n");
      printf("\n");
      printf("Would you like to try another expression using TDP parsing [yes, no]? ");
      scanf("%s", quitProg);
    }
    else{
      break;
    }
  }
}
/*
int main(int argc, char* argv[]) {
  runTDP();
}
*/