Lab01: main.o client.o doublelinkedlist.o node.o
	g++ -std=c++11 -g -Wall main.o client.o doublelinkedlist.o node.o -o Lab01 
main.o: main.cpp client.h
	g++ -std=c++11 -g -Wall -c main.cpp 
client.o: client.h client.cpp
	g++ -std=c++11 -g -Wall -c client.cpp
doublelinkedlist.o: doublelinkedlist.h doublelinkedlist.cpp
	g++ -std=c++11 -g -Wall -c doublelinkedlist.cpp
node.o: node.h node.cpp
	g++ -std=c++11 -g -Wall -c node.cpp 
clean:
	rm *.o Lab01 
