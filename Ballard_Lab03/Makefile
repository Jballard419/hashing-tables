hash_table: main.o
	g++ -g -std=c++11 main.o  -o hash_table
main.o: main.cpp node.h  linkedlist.hpp hash_table.h
	g++ -g -std=c++11 -c main.cpp  hash_table.h

clean:
	rm *.o *.gch hash_table
