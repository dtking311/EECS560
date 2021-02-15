
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "student.h"
#include "linkedlist.h"

const int bucket_size = 11;


class HashTable {

private:																											//private vars

	
	Linkedlist **gotoTable = new Linkedlist*[bucket_size];
		//a pointer to a linkedlist of linkedlists

    int Hashfunction(std::string HashName, int bucket_size);//--
	int FindEntry(int inputKey);	//--
	

public:																												//public vars

	HashTable();	//--
	~HashTable();	//--
	
	bool AddEntry(int idNumber, std::string studentName); //--
	bool RemoveEntry(std::string killStudent); //--
	void PrintEntryList(); //--
	void Output_FindEntry(std::string name); //--


};
#endif




//---------------------------------------------------------------------
