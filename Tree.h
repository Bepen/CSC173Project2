#ifndef PROJECT2_TREE_H
#define PROJECT2_TREE_H

#endif //PROJECT2_TREE_H

typedef struct NODE *TREE; struct NODE;

TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4);
TREE D();
TREE N();
TREE I();
TREE E();
TREE T();
TREE G();
TREE F();
TREE H();
void pre_order(TREE t);
int main();
