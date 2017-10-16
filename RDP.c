#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "RDP.h"

typedef struct NODE *RDP;
struct NODE {
    char label;
    RDP leftmostChild, rightSibling;
};

RDP parseTree;
char *nextTerminal;
int indentCounter = 0;

RDP makeNode0(char x){
    RDP root;
    root = (RDP)malloc(sizeof(struct NODE));
    root->label = x;
    root->leftmostChild = NULL;
    root->rightSibling = NULL;
    return root;
}
RDP makeNode1(char x, RDP t){
    RDP root;
    root = makeNode0(x);
    root->leftmostChild = t;
    return root;
}
RDP makeNode2(char x, RDP t1, RDP t2){
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    return root;
}
RDP makeNode3(char x, RDP t1, RDP t2, RDP t3){
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    return root;
}
RDP makeNode4(char x, RDP t1, RDP t2, RDP t3, RDP t4){
    RDP root;
    root = makeNode1(x, t1);
    t1->rightSibling = t2;
    t2->rightSibling = t3;
    t3->rightSibling = t4;
    return root;
}


RDP E(){
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

RDP T(){
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

RDP G(){
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

RDP H(){
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

RDP F(){
  RDP n, e;
  if(*nextTerminal == '('){
    nextTerminal++;
    e = E();
    if(e == FAILED || *nextTerminal != ')'){
      return FAILED;
    } else{
      return makeNode3('F', makeNode0('('), e, makeNode0(')'));
    }
  } else{
      n = N();
      if(n == FAILED){
        return FAILED;
      } else{
          return makeNode1('F', n);
        }
    }
}

RDP N(){
  RDP d, i;
  d = D();
  i = I();
  if(d == FAILED || i == FAILED){
    return FAILED;
  } else{
    return makeNode2('N', d, i);
  }
}

RDP I(){
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

RDP D(){
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

void pre_order(RDP t) {
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

int main(int argc, char* argv[]){
    nextTerminal = "(10+3)";
    printf("\n");
    parseTree = E();
    pre_order(parseTree);
    printf("\n");
    printf("\n");
    return 0;
}