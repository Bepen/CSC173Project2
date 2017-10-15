#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "Tree.h"

typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftmostChild, rightSibling;
};

TREE parseTree;
char *nextTerminal;
int indentCounter = 0;

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

TREE B(){
    TREE firstB, secondB;
    if(*nextTerminal == '('){
        nextTerminal++;
        firstB = B();
        if(firstB != FAILED && *nextTerminal == ')'){
            nextTerminal++;
            secondB = B();
            if(secondB == FAILED){
                return FAILED;
            } else{
            return makeNode4('B', makeNode0('('), firstB, makeNode0(')'), secondB);
            }
        } else{
            return FAILED;
        }
    }else{
        return makeNode1('B', makeNode0('e'));
    }

}

/*
TREE E(){
}
TREE T(){
}
TREE G(){
}
TREE F(){
}
TREE H(){
}
*/
TREE N(){
  TREE d, i;
  d = D();
  if(d == FAILED){
    return FAILED;
  } else{
    return makeNode1('N', d);
  }
}

TREE I(){
  TREE n;
  n = N();
  if(n == FAILED){
    return FAILED;
  } else if(nextTerminal == NULL){
    return makeNode1('I', makeNode0('e'));
  } else {
    return makeNode1('I', n);
  }
}

TREE D(){
  if((*nextTerminal == '0') || (*nextTerminal == '1')
  || (*nextTerminal == '2') || (*nextTerminal == '3')
  || (*nextTerminal == '4') || (*nextTerminal == '5')
  || (*nextTerminal == '6') || (*nextTerminal == '7')
  || (*nextTerminal == '8') || (*nextTerminal == '9')){
    return makeNode1('D', makeNode0(*nextTerminal));
  }
  else{
    return FAILED;
  }
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

int main(){
    /*
    nextTerminal = "()()";
    parseTree = B();
    pre_order(parseTree);
    */
    nextTerminal = "12";
    parseTree = I();
    pre_order(parseTree);
    printf("\n");
    return 0;
}
