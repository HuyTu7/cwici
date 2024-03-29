/*
 *  * lexer.h Header file for lexer component
 *   */

#ifndef LEXER_H
#define LEXER_H

#define MAX_FIELD 100

#define WORD_TOK 101
#define NUM_TOK 102
#define EOL_TOK 103
#define UNK_TOK 104
#define EOP_TOK 105

void initLexer(char *fileName);
int getToken();
char * getLexeme();
int getLineNumber(); /* optionally can provide helpful error messages */

#endif
