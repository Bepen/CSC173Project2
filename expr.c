#define FAILED NULL
#include "stdio.h"
#include "stdlib.h"
#include "expr.h"
#include "RDP.c"
#include "TableDrivenParsing.c"

int main(int argc, char* argv[]){
  runRDP(); //runs the recursive descent parser
  runTDP(); //runs the table driven parser
}
