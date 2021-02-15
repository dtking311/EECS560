
#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "HashTable.h"
#include "student.h"


class Client {

private:																											//private vars

    HashTable mainTable;
	

public:																												//public vars

	Client(std::string fileName);
	~Client();
	void Run();


};
#endif




//---------------------------------------------------------------------
