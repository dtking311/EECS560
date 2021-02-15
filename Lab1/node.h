#ifndef NODE_H
#define NODE_H
#include <string>


class Node {

private:																											//private vars

	Node* forwardPointer = nullptr;
    Node* reversePointer = nullptr;

    int data = 0;


public:																												//public vars

	Node(int addition);
	~Node();
	
    Node* getForward();
    Node* getReverse();
    bool setForward(Node* pointer);
    bool setReverse(Node* pointer);
    int getData();




};
#endif




//---------------------------------------------------------------------