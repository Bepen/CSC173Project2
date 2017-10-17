#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "expr.h"
#include "RDP.c"
#include "TableDrivenParsing.c"

int main(int argc, char* argv[]){
  runRDP();
  runTDP();
}
