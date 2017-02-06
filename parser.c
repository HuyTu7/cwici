#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "lexer.h"

void wicProg();
void instrList();
void instr();
void iLP();
void Eols();
void iPrime();

int address = 0;
int currTok;
char tmpOpcode[500];

void parse()
{
    currTok = getToken();
    wicProg();
    if(currTok != EOP_TOK)
    {
        perror("Too much input \n");
    }
}

void wicProg()
{
    if((currTok == WORD_TOK)||(currTok == EOL_TOK))
    {
        instrList();
        Eols();
    }
    else
    {
        perror("Syntax Error \n");
    }
}

void match(int tok)
{
    if(currTok != tok)
    {
        perror("mismatch \n");
    }
    currTok = getToken();

}

void instrList()
{
    if((currTok == WORD_TOK)||(currTok == EOL_TOK))
    {
        Eols();
        instr();
        match(EOL_TOK);
        iLP();
    }
    else
    {
        perror("Syntax Error \n");
    }
}

void instr()
{
    if(currTok == WORD_TOK)
    {
        strcp(tempOpcode, getLexeme());
        match(WORD_TOK);
        iPrime();
    }
    else
    {
        perror("Syntax Error \n");
    }
}

void iLP()
{ 
    if((currTok == WORD_TOK)||(currTok == EOL_TOK))
    {
        instrList();
    }
    else
    {
    }
}

void Eols()
{
    if(currTok == EOL_TOK)
    {
        match(EOL_TOK);
        Eols();          
    }
    else
    {
    }
}

void iPrime()
{
    if(currTok == WORD_TOK)
    {
        insertInstruction(address++, tempOpcode, getLexeme());    
        match(WORD_TOK);
    }
    else if(currTok == NUM_TOK)
    {
        insertInstruction(address++, tempOpcode, getLexeme());    
        match(NUM_TOK);
    }
    else
    {
        insertInstruction(address++, tempOpcode, "");    
    }
}
