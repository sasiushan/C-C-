
maze: prog.o map.o terminal.o
	gcc prog.o map.o terminal.o  -o maze

prog.o: prog.c map.h terminal.h
	gcc -c prog.c -Wall -ansi -pedantic

map.o: map.c map.h
	gcc -c map.c -Wall -ansi -pedantic

terminal.o: terminal.c terminal.h
	gcc -c terminal.c -Wall -ansi -pedantic

clean: 
	rm *.o maze;




