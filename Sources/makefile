blackJack: fonctions.o main.o
	gcc -o blackJack fonctions.o main.o 

fonctions.o: fonctions.c
	gcc -c fonctions.c -W -Wall 
	
main.o: main.c fonctions.h
	gcc -c main.c -W -Wall 
