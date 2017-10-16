#ifndef PROJECT2_RDP_H
#define PROJECT2_RDP_H

#endif //PROJECT2_RDP_H

typedef struct NODE *RDP; struct NODE;

RDP makeNode0(char x);
RDP makeNode1(char x, RDP t);
RDP makeNode4(char x, RDP t1, RDP t2, RDP t3, RDP t4);
RDP D();
RDP N();
RDP I();
RDP E();
RDP T();
RDP G();
RDP F();
RDP H();
void pre_order(RDP t);
void runRDP();