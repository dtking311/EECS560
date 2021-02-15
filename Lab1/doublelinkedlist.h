

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <string>
#include "node.h"


class Doublelinkedlist {

private:																											//private vars

	Node* mainHeadPointer = nullptr;
    Node* mainTailPointer = nullptr;

    int totalNodes = 0;

public:																												//public vars

	Doublelinkedlist();
	~Doublelinkedlist();
	
    bool isEmpty(); //--
    int Length();   //--
    bool Insert(int addition);
    bool InsertInOrder(int addition);  //
                //Read the lab assignment wrong. This is not used for
                //lab1, as it orders the numbers in ascending order
                //rather than keeping them in the order they were written
                //in. This method doesnt fully work, but is very close.

    bool Delete(int deletion);//--
    bool Find(int search);  //--
    void FindPrev(int search);//--
    void AppendList();//--
    void ForwardTraverse(); //--
    void BackwardTraverse(); //--
    void displayList(); //--


};
#endif




//---------------------------------------------------------------------