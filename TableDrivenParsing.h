typedef struct NODE *TREE; struct NODE;

TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4);
void pre_order(TREE t);
int main();
