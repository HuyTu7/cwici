/*
 * lexer_test.c Tests the lexer component
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

// only testing smallish WIC program
int tokenStream[100];
char *lexemeStream[100];

void createWIC(char *wicFile, int *tokenStream, char **lexemeStream);

int main(int argc, char *argv[0]) {
  int currTok;
  int expectedTokenIndex = 0;
  char *wicFile = "lexerTest.wic";

  printf("The lexer_test program creates a WIC program file \n");
  printf("named \"lexerTest.wic\" and then repeatedly calls the lexer\n");
  printf("functions: getToken, getLexeme.\n");
  printf("Errors are noted, so if the output is clean then it's working!\n");
  printf("...\n");

  // Set up what is expected!
  createWIC(wicFile, tokenStream, lexemeStream);

  // Use lexer's getToken to see what we find...
  initLexer(wicFile);
  while ( (currTok=getToken()) != EOP_TOK) {
    int expectTok = tokenStream[expectedTokenIndex];
    if (currTok != expectTok) {
      fprintf(stderr, "FAILURE: got %d expected %d\n",currTok,expectTok);
    }
    else if (currTok == NUM_TOK || currTok == WORD_TOK) {
      char *expectLexeme = lexemeStream[expectedTokenIndex];
      if (strcmp(expectLexeme, getLexeme()) != 0) {
	fprintf(stderr, "FAILURE: got lexeme %s expected %s\n",
		getLexeme(),expectLexeme);
      }
    }
    expectedTokenIndex++;
  }
  printf("all done.\n");
  return 0;
}

