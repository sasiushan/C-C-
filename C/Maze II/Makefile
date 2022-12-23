maze: prog.o map.o terminal.o linkList.o openFile.o
	gcc prog.o map.o terminal.o linkList.o openFile.o -o maze

prog.o: prog.c map.h terminal.h linkList.c openFile.c 
	gcc -c prog.c -Wall -ansi -pedantic

map.o: map.c map.h 
	gcc -c map.c -Wall -ansi -pedantic

terminal.o: terminal.c terminal.h
	gcc -c terminal.c -Wall -ansi -pedantic

linkList.o: linkList.c linkList.h
	gcc -c linkList.c -Wall -ansi -pedantic

openFile.c: openFile.c openFile.h
	gcc -c openFile.c -Wall -ansi -pedantic 	

clean: 
	rm *.o maze;




