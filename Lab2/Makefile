Lab02: main.o client.o HashTable.o student.o linkedlist.o 
	g++ -std=c++11 -g -Wall main.o client.o HashTable.o student.o linkedlist.o -o Lab02 
main.o: main.cpp client.h
	g++ -std=c++11 -g -Wall -c main.cpp 
client.o: client.h client.cpp
	g++ -std=c++11 -g -Wall -c client.cpp
HashTable.o: HashTable.h HashTable.cpp
	g++ -std=c++11 -g -Wall -c HashTable.cpp
student.o: student.h student.cpp
	g++ -std=c++11 -g -Wall -c student.cpp
linkedlist.o: linkedlist.h linkedlist.cpp
	g++ -std=c++11 -g -Wall -c linkedlist.cpp
clean:
	rm *.o Lab01 
