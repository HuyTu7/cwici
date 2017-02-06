#WIC Interpreter in C
========

This project exists to directly execute WIC programs through an interpreter written in C.
Wren is a small imperative teaching language and WIC stands for
Wren Intermediate Code, and is just a low level intermediate version
of wren.

To run the program, dl all source and run make, it will explain the make targets,
all of which will run execution on already written tests. If you wish to write
your own WIC and have this interpret it, just write a valid .wic file then 
run ./cwici YOURTEST.wic 

As well, you can say 'make runAll' and it will run all of the tests that I wrote.
