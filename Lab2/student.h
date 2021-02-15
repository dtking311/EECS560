
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
//#include "HashTable.h"


class Student {

private:																											//private vars

    int key = 0;
    std::string StuName = "";
    int idnum = 0;
    Student* nextNode;
	

public:																												//public vars

	Student(int id, std::string name, int inputKey);			
	~Student();

	std::string getName();
    int getid();
    int getKey();
    Student* getNext();
    void setNext(Student* nextPointer);


};
#endif




//---------------------------------------------------------------------
