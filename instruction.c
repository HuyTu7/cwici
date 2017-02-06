#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instruction.h"
#include "table.h"
#include "stack.h"

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

/* An alternate C design: don't expose internal data structure.
 * Previously (stack and table), I showed the data structure and 
 * prototyped the methods.
 * Here, we keep the structure hidden inside the .c file and only expose
 * the methods.  (You might be thinking "hidden?" how is it hidden since
 * you can just look at it.  But consider that I could deliver the header
 * and an object file or library where you couldn't see it.)
 */


typedef struct{
    char opcode[MAX_PROGRAM_SIZE];
    char operand[MAX_PROGRAM_SIZE];
} instructionType;

typedef struct
{
    int numItems;
    instructionType instrE[MAX_PROGRAM_SIZE]; 
} instructionTable;

instructionTable instrT;

/* Prepares instruction structures for execution. */
void initialize() 
{
    instrT.numItems = 0;
    initTable(&table);
    initStack(&stack);
}
/* Called from within parser as instructions are parsed/encountered.
 *  All of these parameters are "in" parameters.
 * As instructions are inserted, we must also do any other duties:
 * + "label instructions" must add to the "jump table"
 * + "label instructions" are "backwards" with operand (label) first
 *     and opcode (the word "label" itself) second
 */
void insertInstruction(int address, char *opcode, char *operand);
{
    char *temp;
    if (strcmp(operand, "label") == 0)
    {   
        *temp = *opcode; 
        *opcode = *operand;
        *operand = *temp;
    }
    
    instruction tempInst;
    strcp(tempInst.opcode, opcode);
    strcp(tempInst.operand, operand);

    instrT -> table[address] = tempInst;
    instrT -> numItems++; 
}
/* Instructions are fetched during "execution" of WIC program.
 * address is an "in" parameter, 
 * opcode and operand are "out" parameters
 * operand may be NULL for opcode-only instructions like "add"
 */
void fetchInstruction(int address, char *opcode, char *operand);
{
    strcp(opcode, instrT->table[address].opcode);
    strcp(operand, instrT->table[address].operand);
}
/* Using a lexer/parser, we don't need the helper hasOperand function,
 * but if you wrote it, it is okay.  The book's way of reading input file
 * needed it because it needed to know if next thing read (next token) was
 * operand or next instruction.  Our grammar imparts this structure/knowledge.
 *
 * int hasOperand(char *opcode);
 */

/* Usual debugging method... */
void printInstructions();
{
    int i;
    for( i = 0; i < Instruction->MAX_PROGRAM_SIZE; i++)
    {
         printf("opcode: %s, operand: %s\n", 
                instrT->table[i].opcode, 
                instrT->table[i].operand);
    }
}
/* Lastly, we need prototypes for methods that will perform/execute the
 * WIC instructions.  As a first test, we'll work for the simplest WIC 
 * program (a single halt instruction).  As you increase your testing by 
 * adding additional instructions, you'll need to add to this list of
 * prototypes.
 *
 * Note that there are some name conflicts with pre-defined functions.  For
 * example, "div" is in a library somewhere.  So try a div prototype, see the
 * error notice, then rename your method (maybe something like "divide" or
 * "wic_div" or whatever.
 */
int halt(int pc)
{
    printf("program halted\n");
    return EOP_TOK;
}
void get(char *operand)
{
    printf("Input a variable: %s > ", operand);
    char i[MAX_FIELD];
    int val;
    scanf("%s", &input);
    
}
void put(char *operand);
void push(char *operand);
void subtract();
void multiply();

