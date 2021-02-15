

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include "student.h"


class Linkedlist {

private:																											//private vars

	Student* mainHeadPointer = nullptr;

    int totalNodes = 0;

public:																												//public vars

	Linkedlist();
	~Linkedlist();
	

    int FindSpot(int keySpot);  //--
    Student* getStudent(int position); //--
    void printListInfo(); //--
    void InsertStu(int idNum, std::string studName, int hash); //--
    void DeleteStu(int linstPosition); //--
    bool Find(int key); //



};
#endif




//---------------------------------------------------------------------