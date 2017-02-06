
default: 
	@echo "usage: make <target>"
	@echo "available targets: stack, table, lexer, parser"

stack: teststack.c stack.h stack.c 
	gcc teststack.c stack.c -o teststack

table: testtable.c table.h table.c 
	gcc testtable.c table.c -o testtable

lexer: lexer_test.c lexer.h lexer.c
	gcc lexer_test.c lexer.c -o lexer_test

parser: lexer.c parser_test.c parser.h parser.c
	gcc lexer.c parser_test.c parser.c -o parser_test
