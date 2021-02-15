
#include "node.h"


Node::Node(int addition){

    forwardPointer = nullptr;
    reversePointer = nullptr;

    data = addition;

}

Node::~Node(){

    forwardPointer = nullptr;
    reversePointer = nullptr;

    data = 0;

}
Node* Node::getForward(){

    return forwardPointer;

}
Node* Node::getReverse(){

    return reversePointer;

}
bool Node::setForward(Node* pointer){

    forwardPointer = pointer;
    return true;

}
bool Node::setReverse(Node* pointer){

    reversePointer = pointer;
    return true;

}
int Node::getData(){

    return data;

}

