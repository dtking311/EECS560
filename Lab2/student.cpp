#include "student.h"

Student::Student(int id, std::string name, int inputKey){

    key = inputKey;
    StuName = name;
    idnum = id;
    nextNode = nullptr;

}

Student::~Student(){

    key = 0;
    StuName = "";
    idnum = 0;
    nextNode = nullptr;

}

std::string Student::getName(){

    return StuName;

}

int Student::getid(){

    return idnum;

}

int Student::getKey(){

    return key;

}

Student* Student::getNext(){

    return nextNode;

}

void Student::setNext(Student* nextPointer ){

    nextNode = nextPointer;

}