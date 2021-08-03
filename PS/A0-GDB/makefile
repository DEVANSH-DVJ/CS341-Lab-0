./djikstra: heap.o djikstra.o
	g++ -std=c++17 -g -o djikstra heap.o djikstra.o
heap.o: heap.hpp heap.cpp
	g++ -std=c++17 -g -o heap.o -c heap.cpp
djikstra.o: heap.hpp djikstra.cpp
	g++ -std=c++17 -g -o djikstra.o -c djikstra.cpp

gdb: ./djikstra
	gdb ./djikstra

clean:
	rm *.o *.exe *.out ./djikstra
