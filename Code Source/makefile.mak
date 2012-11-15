fonctions.o : fonctions.c 
			gcc -c fonctions.c
			
main.o : main.c
			gcc -c main.c
		
all : fonctions.o main.o
			gcc -o main *.o
			
clean : rm *.o