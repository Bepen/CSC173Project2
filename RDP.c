#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "RDP.h"
#include "string.h"

typedef struct NODE *RDP;
struct NODE { //trees have a leftmost child and a right sibling
    char label;
    RDP leftmostChild, rightSibling;
};

RDP parseTree;
char *nextTerminal;
int indentCounter = 0;

RDP makeNode0(char x){ //creates a leaf
    RDP root;
    root = (RDP)malloc(sizeof(struct NODE));
    root->label = x;
    root->leftmostChild = NULL;
    root->rightSibling = NULL;
    return root;
}
RDP makeNode1(char x, RDP t){ //creates a tree with one child
    RDP root;
    root = makeNode0(x);
    root->leftmostChild = t;
    return root;
}
RDP makeNode2(char x, RDP t1, RDP t2){ //creates a tree with two children
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    return root;
}
RDP makeNode3(char x, RDP t1, RDP t2, RDP t3){ //creates a tree with three children
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    return root;
}
RDP makeNode4(char x, RDP t1, RDP t2, RDP t3, RDP t4){ //creates a tree with four children
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    t3->rightSibling = t4;
    return root;
}


RDP E(){ //creates a tree for E
  RDP t, g;
  t = T();
  if(t == FAILED){
    printf("Incorrect format, parse has failed.");
    return FAILED;
  } else{
    g = G();
    if(g == FAILED){
      printf("Incorrect format. Parse has failed.");
      return FAILED;
    } else{
      return makeNode2('E', t, g);
    }
  }
}

RDP T(){ //creates a tree for T
  RDP f, h;
  f = F();
  if(f == FAILED){
    return FAILED;
  } else{
    h = H();
    if(h == FAILED){
      return FAILED;
    } else{
      return makeNode2('T', f, h);
    }
  }
}

RDP G(){ //creates a tree for G
  RDP t, g;
  if(*nextTerminal == '+'){
    nextTerminal++;
    t = T();
    if (t == FAILED){
      return FAILED;
    } else {
      g = G();
      if(g == FAILED){
        return FAILED;
      } else{
        return makeNode3('G', makeNode0('+'), t, g);
      }
    }
  } else if(*nextTerminal == '-'){
    nextTerminal++;
    t = T();
    if (t == FAILED){
      return FAILED;
    } else {
      g = G();
      if(g == FAILED){
        return FAILED;
      } else{
        return makeNode3('G', makeNode0('-'), t, g);
      }
    }
  } else{
    return makeNode1('G', makeNode0('e'));
  }
}

RDP H(){ //creates a tree for H
  RDP f, h;
  if(*nextTerminal == '*'){
    nextTerminal++;
    f = F();
    if (f == FAILED){
      return FAILED;
    } else {
      h = H();
      if(h == FAILED){
        return FAILED;
      } else{
        return makeNode3('H', makeNode0('*'), f, h);
      }
    }
  } else if(*nextTerminal == '/'){
    nextTerminal++;
    f = F();
    if (f == FAILED){
      return FAILED;
    } else {
      h = H();
      if(h == FAILED){
        return FAILED;
      } else{
        return makeNode3('H', makeNode0('/'), f, h);
      }
    }
  } else{
    return makeNode1('H', makeNode0('e'));
  }
}

RDP F(){ //creates a tree for F
  RDP n, e;
  if(*nextTerminal != '('){
      n = N();
      if(n == FAILED){
        return FAILED;
      } else{
          return makeNode1('F', n);
        }
  } else{
    nextTerminal++;
    e = E();
    if(e == FAILED || *nextTerminal != ')'){
      return FAILED;
    } else{
      return makeNode3('F', makeNode0('('), e, makeNode0(')'));
    }
  }
}

RDP N(){ //creates a tree for N
  RDP d, i;
  d = D();
  i = I();
  if(d == FAILED || i == FAILED){
    return FAILED;
  } else{
    return makeNode2('N', d, i);
  }
}

RDP I(){ //creates a tree for I
  RDP n;
  if(!((*nextTerminal == '0') || (*nextTerminal == '1')
  || (*nextTerminal == '2') || (*nextTerminal == '3')
  || (*nextTerminal == '4') || (*nextTerminal == '5')
  || (*nextTerminal == '6') || (*nextTerminal == '7')
  || (*nextTerminal == '8') || (*nextTerminal == '9'))){
    return makeNode1('I', makeNode0('e'));
  } else{
    n = N();
    return makeNode1('I', n);
  }
}

RDP D(){ //creates a tree for D
  if((*nextTerminal == '0') || (*nextTerminal == '1')
  || (*nextTerminal == '2') || (*nextTerminal == '3')
  || (*nextTerminal == '4') || (*nextTerminal == '5')
  || (*nextTerminal == '6') || (*nextTerminal == '7')
  || (*nextTerminal == '8') || (*nextTerminal == '9')){
    char temp = *nextTerminal;
    nextTerminal++;
    return makeNode1('D', makeNode0(temp));
  }
  else{
    return FAILED;
  }
}

void pre_order(RDP t) { //preorder traversal of the tree
  if (t == NULL) {
    indentCounter--;
    return;
  } else {
    printf("\n");
    for(int i = 0; i<= indentCounter; i++){
      printf("  ");
    }
    if(t->label == 'B' || t->label == 'D' || t->label == 'N' ||
       t->label == 'I' || t->label == 'F' || t->label == 'E' ||
       t->label == 'T' || t->label == 'G' || t->label == 'H'){
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

void runRDP(){ //runs the recursive descent parser
  printf("\n");
  printf("Welcome to the recursive descent parser. \n");
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
      nextTerminal = expression;
      parseTree = E();
      pre_order(parseTree);
      printf("\n");
      printf("\n");
      printf("Would you like to try another expression using RDP parsing [yes, no]? ");
      scanf("%s", quitProg);
    }
    else{
      break;
    }
  }
}