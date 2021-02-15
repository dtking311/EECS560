
#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "doublelinkedlist.h"


class Client {

private:																											//private vars

    Doublelinkedlist mainlist;
	

public:																												//public vars

	Client(std::string fileName, bool InOrder);
				//Read the lab assignment wrong. This is only partially used for
                //lab1, as it orders the numbers in ascending order
                //rather than keeping them in the order they were written
                //in. This is functionality is disabled for lab1 durring the
				//call in main.cpp
	~Client();
	void Run();


};
#endif




//---------------------------------------------------------------------
