/*
 * cwici.c A WIC interpreter written in C.
 *
 * This version differs from textbook description in that we use
 * a lexer/parser to handle structured input.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "instruction.h"

void execute();

int main(int argc, char *argv[]) {
  char *wicFilename;

  if (argc == 1) {
    // no wic file on command line
    fprintf(stderr, "usage: %s <wic filename>\n",argv[0]);
    exit(1);
  }
  else wicFilename = argv[1];

  initLexer(wicFilename);
  parse();
  printf("Congrats! Looks like that file parsed successfully.\n");
  printf("Here is the instruction list constructed...\n");
  printInstructions();

  printf("\n\nNow attempting to execute the program...\n\n");
  execute();
}

void execute() {
  int pc = 0;
  char opcode[MAX_FIELD];
  char operand[MAX_FIELD];

  while (pc != EOP) { // halt instruction sets program counter to EOP
    fetchInstruction(pc, opcode, operand);

    if (strcmp(opcode,"halt")==0) pc = halt(pc);
    else {
      printf("unknown instruction %s %s\n",opcode, operand);
      exit(1);
    }
  }
}
