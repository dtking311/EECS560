
#include "doublelinkedlist.h"
#include <iostream>
#include <fstream>

Doublelinkedlist::Doublelinkedlist(){

    totalNodes = 0;

    mainHeadPointer = nullptr;
    mainTailPointer = nullptr;



}
Doublelinkedlist::~Doublelinkedlist(){

    Node* deletePointer = mainTailPointer;
    Node* transPointer = mainTailPointer;


    for(int i = totalNodes; i != 0; i--){

        //std::cout << "deleting: " << i << "\n\n"; //for diag

        transPointer = deletePointer->getReverse();
        delete(deletePointer);

        deletePointer = transPointer;

    }

    transPointer = nullptr;
    deletePointer = nullptr;
    mainHeadPointer = nullptr;
    mainTailPointer = nullptr;


}
	
bool Doublelinkedlist::isEmpty(){

    if(totalNodes == 0){

        return true;

    } else {

        return false;

    }

}
int Doublelinkedlist::Length(){

    return totalNodes;

}

bool Doublelinkedlist::Insert(int addition){

        if(totalNodes == 0){                //no nodes

        Node* newNode = new Node(addition);
        mainHeadPointer = newNode;
        mainTailPointer = newNode;

        totalNodes++;
        newNode = nullptr;
        return true;

    } else {

        if(Find(addition) == true){        //if duplicate

            return false;

        } else {                    

            Node* CreatePointer = new Node(addition);
            Node* currentPointer = mainTailPointer;
            totalNodes++;
            
            currentPointer->setForward(CreatePointer);
            CreatePointer->setReverse(currentPointer);

            mainTailPointer = CreatePointer;
            CreatePointer = nullptr;
            currentPointer = nullptr;
  
            return true;

        }
    }

}


bool Doublelinkedlist::InsertInOrder(int addition){

    if(totalNodes == 0){                //no nodes

        Node* newNode = new Node(addition);
        mainHeadPointer = newNode;
        mainTailPointer = newNode;

        totalNodes++;
        newNode = nullptr;
        return true;

    } else {

        if(Find(addition) == true){        //if duplicate

            return false;

        } else {                    //begin search for placement

            //Node* newNode = new Node(addition);

            Node* currentPointer = mainHeadPointer;
            Node* traversePointer = mainHeadPointer;
            totalNodes++;
            //int nodecounter = totalNodes - 1;

            while(true){

                //std::cout << "\nnodecounter: " << nodecounter;

                if(traversePointer == nullptr){ // && nodecounter == 0){         //if you run into last node in list


                        std::cout << "\n$$$DIAG$$$ ran into last node - " << addition << "\n";
                        Node* CreatePointer = new Node(addition);
                        //traversePointer = new Node(addition);
                        currentPointer->setForward(CreatePointer);
                        CreatePointer->setReverse(currentPointer);
                        mainTailPointer = CreatePointer;

                        traversePointer = nullptr;  //delete dangling pointers.
                        currentPointer = nullptr;
                        CreatePointer = nullptr;

                        return true;

                    }

                if(currentPointer->getData() < addition){  //move forward

                    currentPointer = traversePointer;
                    traversePointer = currentPointer->getForward();

                } else {    //found spot

                    std::cout << "\n$$$DIAG$$$ found spot - " << addition << "\n";
                    Node* CreatePointer = new Node(addition);
                    traversePointer = currentPointer->getReverse();

                    if(traversePointer == nullptr){     //if this is being put into first position

                        std::cout << "\n$$$DIAG$$$ first position - " << addition << "\n";
                        CreatePointer->setForward(currentPointer);
                        currentPointer->setReverse(CreatePointer);
                        mainHeadPointer = CreatePointer;

                        CreatePointer = nullptr;        //delete dangling pointers.
                        traversePointer = nullptr;
                        currentPointer = nullptr;

                        return true;

                    }

                    traversePointer->setForward(CreatePointer);     //before -> new
                    CreatePointer->setReverse(traversePointer);     //before <- new
                    CreatePointer->setForward(currentPointer);      //new -> after
                    currentPointer->setReverse(CreatePointer);      //new <- after

                    CreatePointer = nullptr;        //delete dangling pointers.
                    traversePointer = nullptr;
                    currentPointer = nullptr;

                    return true;

                } //end search
                
                //nodecounter--;

            }   //end while
        }       //end search
    }
    




    totalNodes++;
    return true;


}
bool Doublelinkedlist::Delete(int deletion){

    Node* deletePointer = mainHeadPointer;


    if(Find(deletion) == false){      //not in list case

        std::cout << "\n" << deletion << " - is not in the list.\n";
        return false;

    }

    if(mainHeadPointer->getData() == deletion){   //first in list case

        mainHeadPointer = deletePointer->getForward();
        mainHeadPointer->setReverse(nullptr);

        deletePointer->setForward(nullptr);
        delete(deletePointer);
        deletePointer = nullptr;

        totalNodes--;

        return true;

    }

    


    Node* AfterPointer = mainHeadPointer->getForward();
    Node* BeforePointer = nullptr;

    while(true){        //search

        if(AfterPointer->getData() == deletion){



            if(AfterPointer->getForward() == nullptr){      //last in list case

                deletePointer = AfterPointer;
                BeforePointer = deletePointer->getReverse();

                mainTailPointer = BeforePointer;
                
                deletePointer->setForward(nullptr);
                deletePointer->setReverse(nullptr);

                BeforePointer->setForward(nullptr);

                delete(deletePointer);
                deletePointer = nullptr;
                BeforePointer = nullptr;
                AfterPointer = nullptr;

                totalNodes--;
                return true;


            }


            deletePointer = AfterPointer;
            AfterPointer = deletePointer->getForward();
            BeforePointer = deletePointer->getReverse();

            deletePointer->setForward(nullptr);
            deletePointer->setReverse(nullptr);

            BeforePointer->setForward(AfterPointer);
            AfterPointer->setReverse(BeforePointer);

            delete(deletePointer);
            deletePointer = nullptr;
            BeforePointer = nullptr;
            AfterPointer = nullptr;

            totalNodes--;
            return true;

        } 
        
        AfterPointer = AfterPointer->getForward(); //step

    }

    std::cout << "\n\n\nError in search of deletion\n\n\n";
    return false;


}
bool Doublelinkedlist::Find(int search){


    if(mainHeadPointer->getData() == search){   //first in list case

        return true;

    }

    Node* SearchPointer = mainHeadPointer->getForward();

    while(true){

        //std::cout << search;
        if(SearchPointer == nullptr){

            SearchPointer = nullptr;
            return false;

        } 
        if(SearchPointer->getData() == search){

            SearchPointer = nullptr;
            return true;

        } 

        SearchPointer = SearchPointer->getForward();

    }

}
void Doublelinkedlist::FindPrev(int search){

    if(mainHeadPointer->getData() == search){   //first in list case

        std::cout << "\n" << search << " - is the first entry in list. Therefore no number proceeds it! \n";
        return;

    }

    if(Find(search) == false){      //not in list case

        std::cout << "\n" << search << " - is not in the list.\n";
        return;

    }

    Node* SearchPointer = mainHeadPointer->getForward();

    while(true){        //search

        if(SearchPointer->getData() == search){

            SearchPointer = SearchPointer->getReverse();

            std::cout << "\n" << SearchPointer->getData() << " - is the previous number to " << search << "\n";
            return;

        } 
        
        SearchPointer = SearchPointer->getForward();

    }


}
void Doublelinkedlist::AppendList(){

    /*
    To not use an array like stated in the lab assignment. This creates a new input file,
    similar to how it reads the original list of numbers. Then deletes that temporary input
    file after it appends all the elements into the main list. Using an array would be much
    easier and likely run much more efficently. 
    */

    std::ofstream toFile("tempFile.txt");           //Create a temp file to host new list

    std::cout << "Enter a list of numbers to insert into append into your current list: ";
    std::string userInput;
    std::cin.ignore();
    
    getline(std::cin, userInput);                   //Write new list data to tempFile
    toFile << userInput;
   
    toFile.close();

    //----------------------------------------------------------------------------------

    std::ifstream inFile;                           //Start reading from file
    int tempHolder = 0;
    inFile.open("tempFile.txt");
    
    while(inFile.eof() != true){

	    inFile >> tempHolder;

        if (Insert(tempHolder) == true){

            std::cout << "Item added to list - with value: " << tempHolder << " . \n";

        } else {

            std::cout << "Item NOT added to list - with value: " << tempHolder << " . \n";

        }
    }   

    inFile.close();
    remove("tempFile.txt");                         //Delete the tempFile from existance


}


void Doublelinkedlist::ForwardTraverse(){

    std::cout << "\nCurrent List is: [ " << mainHeadPointer->getData() << " , ";
    Node* SearchPointer = mainHeadPointer->getForward();

    while(true){        //search

        if(SearchPointer->getForward() == nullptr){
            std::cout << SearchPointer->getData() << " ]. ---> ";
            break;
        }

        std::cout << SearchPointer->getData() << " , ";
        SearchPointer = SearchPointer->getForward();
    }

    std::cout << "In forward traversal\n\n";

}
void Doublelinkedlist::BackwardTraverse(){

std::cout << "\nCurrent List is: [ " << mainTailPointer->getData() << " , ";
    Node* SearchPointer = mainTailPointer->getReverse();

    while(true){        //search

        if(SearchPointer->getReverse() == nullptr){

            std::cout << SearchPointer->getData() << " ]. ---> ";

            break;
        }

        std::cout << SearchPointer->getData() << " , ";
        SearchPointer = SearchPointer->getReverse();
    }

    std::cout << "In reverse traversal\n\n";


}

void Doublelinkedlist::displayList(){


    Node* CurrentPointer = mainHeadPointer;
    //Node* ReversePointer = mainHeadPointer->getReverse();
    //Node* ForwardPointer = mainHeadPointer->getForward();

    for(int i = totalNodes ; i != 0 ; i--){        //search


        std::cout << "\n" << i << ")  [";

        if(CurrentPointer->getReverse() == nullptr){

            std::cout << " nullptr";

        }else{

            std::cout << " " << CurrentPointer->getReverse()->getData();

        }
        
        std::cout << " < " << CurrentPointer->getData() << " > ";


        if(CurrentPointer->getForward() == nullptr){

            std::cout << "nullptr ";

        }else{

            std::cout << CurrentPointer->getForward()->getData() << " ";

        }

        std::cout << "]";

        CurrentPointer = CurrentPointer->getForward();
        

    }

    std::cout << "\n\n\n";


}

