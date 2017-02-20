hash_table_test: main.o hash_table_open.o node.o Linkedlist.o
	g++ -g -std=c++11 main.o  -o hash_table_test
main.o: main.cpp  hash_table.h hash_table_open.h
	g++ -g -std=c++11 -c main.cpp  hash_table.h
Hash_table.o: hash_table.h hash_table.hpp
	g++ -Wall -std=c++11 -c hash_table.h
hash_table_open.o: hash_table_open.h hash_table_open.hpp
	g++ -Wall -std=c++11 -c hash_table_open.h
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h

clean:
	rm *.o *.gch hash_table_test
