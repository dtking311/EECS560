



#include "linkedlist.h"
#include <iostream>
#include <fstream>

Linkedlist::Linkedlist(){

    totalNodes = 0;
    mainHeadPointer = nullptr;

}
Linkedlist::~Linkedlist(){

    if(totalNodes == 0){

        mainHeadPointer = nullptr;

        return;

    } else if(totalNodes == 1){

        delete mainHeadPointer;
        mainHeadPointer = nullptr;

        return;

    } else {

        Student* deletePointer = mainHeadPointer;
        Student* transPointer = deletePointer->getNext();

        while(transPointer != nullptr){

            delete deletePointer;
            deletePointer = transPointer;
            transPointer = transPointer->getNext();


        }

        delete deletePointer;

        deletePointer = nullptr;
        transPointer = nullptr;
        mainHeadPointer = nullptr;


    }
}
	


int Linkedlist::FindSpot(int keySpot){

    Student* CurrentPointer = mainHeadPointer;
    
    for(int i = 0; i != totalNodes; i++){

        if(CurrentPointer == nullptr){

            return -1;

        }
        if(CurrentPointer->getKey() == keySpot){

            return i;

        }else{

            CurrentPointer = CurrentPointer->getNext();

        }
    }

    return -2;
}

Student* Linkedlist::getStudent(int position){

    Student* currentPointer = mainHeadPointer;

    for(int i=0; i != position; i++){

        if(currentPointer == nullptr){

            return nullptr;

        }

        currentPointer = currentPointer->getNext();

    }

    return currentPointer;

}

void Linkedlist::printListInfo(){

    Student* currentPointer = mainHeadPointer;

    for(int i = 0; i != totalNodes; i++){

        if(currentPointer == nullptr){ //just in case

            std::cout << " -> *";
            return;

        }

        std::cout << " -> [ " << currentPointer->getid() << " : "
        << currentPointer->getName() << " ]";
        
        currentPointer = currentPointer->getNext();

    }

    if(currentPointer == nullptr){

        std::cout << " -> [null]";
        return;

    }

    currentPointer = nullptr;



}

void Linkedlist::InsertStu(int idNum, std::string studName, int hash){

    Student* newStudent = new Student(idNum, studName, hash);

    if(totalNodes == 0){                //first node

        mainHeadPointer = newStudent;
        totalNodes++;

    } else {            //beyond first node
                    
        Student* curPointer = mainHeadPointer;
        Student* travPointer = curPointer->getNext();

        while(travPointer != nullptr){  //goto end of linked list

            curPointer = travPointer;
            travPointer = travPointer->getNext();

        }

        curPointer->setNext(newStudent);

        totalNodes++;

        curPointer = nullptr;       //remove dangling pointers before out of scope
        travPointer = nullptr;
        }

        return;
}

void Linkedlist::DeleteStu(int listPosition){

    if(totalNodes == 1){            

        delete mainHeadPointer;
        mainHeadPointer = nullptr;
        totalNodes--;

        return;

    }
    if(totalNodes == 2){

        if(listPosition == 1){

            delete (mainHeadPointer->getNext());

        } else {    //if listPosition == 0

            Student* delPointer = mainHeadPointer;
            mainHeadPointer = mainHeadPointer->getNext();

            delete delPointer;
            delPointer = nullptr;

        }

        totalNodes--;
        return;
    }

    if(listPosition == 0){

        Student* delPointer = mainHeadPointer;
        mainHeadPointer = mainHeadPointer->getNext();

        delete delPointer;
        delPointer = nullptr;

        totalNodes--;
        return;

    }

    if(( totalNodes-1 ) > listPosition){  

        Student* curPointer = mainHeadPointer;

        for(int i = 0; i != (listPosition-1); i++){  //Nav to node before position

            curPointer = curPointer->getNext();
        }

        Student* delPointer = curPointer->getNext();
        Student* toPointer = delPointer->getNext();

        delete delPointer;
        curPointer->setNext(toPointer);

        totalNodes--;

        delPointer = nullptr;
        curPointer = nullptr;
        toPointer = nullptr;

        return;
    }
    if (( totalNodes-1 ) == listPosition){

        Student* curPointer = mainHeadPointer;

        for(int i = 0; i != (listPosition-1); i++){  //Nav to node before position

            curPointer = curPointer->getNext();
        }

        Student* delPointer = curPointer->getNext();

        curPointer->setNext(nullptr);
        delete delPointer;

        delPointer = nullptr;
        curPointer = nullptr;

        totalNodes--;
        return;
    }
}

bool Linkedlist::Find(int key){

    if(totalNodes == 0){

        return false;

    }

    if(totalNodes == 1){

        if(mainHeadPointer->getKey() == key){

            return true;

        } else {

            return false;

        }
    }

    Student* curPointer = mainHeadPointer;

    for(int i = 0; i != totalNodes; i++){

        if(curPointer == nullptr){

            return false;

        }

        if(curPointer->getKey() == key){

            return true;

        } 
        curPointer = curPointer->getNext();

    }
    return false;
}


