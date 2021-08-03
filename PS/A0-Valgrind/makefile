./main: argparse.o main.o
	gcc -g main.o argparse.o -o main

main.o: main.c argparse.h
	gcc -g -c main.c -o main.o

argparse.o: argparse.c argparse.h
	gcc -g -c argparse.c -o argparse.o

clean:
	rm *.o *.out *.exe ./main

valgrind: ./main
	valgrind valgrind --leak-check=full --show-leak-kinds=all ./main