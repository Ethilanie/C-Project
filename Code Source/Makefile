fonctions.o: fonctions.c 
	gcc -c fonctions.c
			
prog.o: prog.c
	gcc -c prog.c
	
test.o : test.c
	gcc -c test.c
		
prog : 	fonctions.o prog.o
		gcc -o prog fonctions.o prog.o
		
test : fonctions.o test.o
		gcc -o test fonctions.o test.o
		
all : prog test
			
clean:
	rm *.o *.exe