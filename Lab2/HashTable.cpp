#include <iostream>
#include "HashTable.h"
#include "linkedlist.h"


HashTable::HashTable(){


    for(int i = 0; i != bucket_size; i++){

        gotoTable[i] = new Linkedlist;      //Create the EMPTY Linkedlist per bucket

    }

}

HashTable::~HashTable(){


    for(int i = 0; i != bucket_size; i++){

        delete gotoTable[i];            //Delete the bucket Linkedlist

    }

    delete gotoTable;
    gotoTable = nullptr;

}

int HashTable::Hashfunction(std::string HashName, int bucket_size){

    int HashOutput = 0;

    for(int i = 0; i != int(HashName.length()); i++){

        //std::cout << "\nHashFunc diag:: letter:  " << HashName[i] << " - " << int(HashName[i]);
        HashOutput += int(HashName[i]); //grabs char and converts to ASCII value

    }

    return HashOutput;

}
bool HashTable::AddEntry(int idNumber, std::string studentName){

    //run student through Hashfunction
    //check for duplicate
    //add student to hash table at the bucket AND to the end of the linkedlist.


    
    int hashResult = Hashfunction(studentName, bucket_size);
    int afterMod = hashResult % bucket_size;

    //std::cout << "DIAG::: hashResult = " << hashResult << " , afterMod = " << afterMod << " .\n\n";

    if(FindEntry(hashResult) != -1){    //if not a duplicate

        return false;

    }

    //Student* studentCreator = new Student(idNumber, studentName, hashResult);
    gotoTable[afterMod]->InsertStu(idNumber, studentName, hashResult);

    //studentCreator = nullptr;
    return true;


}

bool HashTable::RemoveEntry(std::string killStudent){

    int hashResult = Hashfunction(killStudent, bucket_size);
    int afterMod = hashResult % bucket_size;

    int EntrySearch = FindEntry(hashResult);

    if(EntrySearch == -1){ //if not found

        return false;

    }

    gotoTable[afterMod]->DeleteStu(EntrySearch);
    return true;
}

void HashTable::PrintEntryList(){

    std::cout << "\n=============================================================\n\n";

    for(int i = 0; i != bucket_size; i++){

        std::cout << i << ":";
        gotoTable[i]->printListInfo();
        std::cout << "\n";

    }

    std::cout << "\n=============================================================\n";

    return;


}

void HashTable::Output_FindEntry(std::string name){

    int hashResult = Hashfunction(name, bucket_size);
    int bucket = hashResult % bucket_size;
    int positionBucket = (FindEntry(hashResult)); //+1

    if(positionBucket == -1){

        std::cout << "\n\nThe student: " << name << " could not be found!\n";

    }else{

        int studentID = gotoTable[bucket]->getStudent(positionBucket)->getid();
        
        std::cout << "\n\nThe student: " << name << " , with id: "<< studentID << " ...was found at\n";
        std::cout << "------- ------- ------- ------- ------- -------\n";
        std::cout << "Bucket: " << bucket << " , position --> " << (positionBucket) << "\n\n";


                                                                            // -1 ^

    }
}

int HashTable::FindEntry(int inputKey){

    int afterMod = inputKey % bucket_size;

    if (gotoTable[afterMod]->Find(inputKey) == true){ //returns if found

        return (gotoTable[afterMod]->FindSpot(inputKey)); //returns spot(NOT including afterMod)

    } else {

     return -1;  //not found

    }

    return -2;

}