#include "client.h"
#include <string>
#include <fstream>
#include <iostream>

void Client::Run(){
while(true) { 



	int userInput = 0;

    std::cout << "________________________________________________";
    std::cout << "\nChoose one operation from the options below:\n\n"

                 "1) Is Empty\n"
                 "2) Length\n"
                 "3) Insert\n"
                 "4) Delete\n"
                 "5) Find\n"
                 "6) Find Prev\n"
                 "7) Append List\n"
                 "8) Forward Traverse\n"
                 "9) Reverse Traverse\n"
                 "10) Display All Nodes in List\n"
                 "11) Exit\n";
    std::cout << "________________________________________________\n\n";

    std::cin >> userInput; //check for invalid case here!!!!!!!


switch (userInput) {
    case 1:
    {

        if(mainlist.isEmpty() == true){

            std::cout << "The list is empty\n";
            
        } else {

            std::cout << "The list is not empty!\n";

        }
        break;
    }
    case 2:
    {
        std::cout << "the list contains " << mainlist.Length() << " items\n";
        break;
    }
    case 3:
    {
        std::cout << "Enter a number to insert into the list: ";
        int userInput3 = 0;
        std::cin >> userInput3;
        if(mainlist.Insert(userInput3) == true){

            std::cout << "Item has been inserted!\n";
        } else {

            std::cout << "Item was not inserted into the list\n";

        }
        break;
    }
    case 4:
    {
        std::cout << "Enter a number to be deleted from the list: ";
        int userInput4 = 0;
        std::cin >> userInput4;
        if(mainlist.Delete(userInput4) == true){

            std::cout << "Item has been deleted!\n";
        } else {

            std::cout << "Item was not deleted from the list\n";

        }
        break;
    }
    case 5:
    {
        std::cout << "Enter a number to find in the list: ";
        int userInput5 = 0;
        std::cin >> userInput5;
        if(mainlist.Find(userInput5) == true){

            std::cout << userInput5 << " was found in the list!\n";

        } else {

            std::cout << userInput5 << " was not found in the list!\n";

        }
        break;
    }
    case 6:
    {
        std::cout << "Enter a number to find BEFORE the item in the list:\n";
        int userInput6 = 0;
        std::cin >> userInput6;
        mainlist.FindPrev(userInput6);
        break;
    }
    case 7:
    {
        mainlist.AppendList();
        break;
        
    }
    case 8:
    {
        mainlist.ForwardTraverse();
        break;
    }
    case 9:
    {
        mainlist.BackwardTraverse();
        break;
    }
    case 10:
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\nNode Data:\n\nNode#) [ Reverse Pointer < Node Data > Forward Pointer ]\n\n";
        mainlist.displayList();
        break;
    }
    case 11:
    {
        return;
        break;
    }
    default:
    {
        return;
        break;
    }

}
}
}




Client::~Client(){	//destructor

	//delete[] allRecords;

}	




Client::Client(std::string fileName, bool InOrder){


int tempHolder = 0;

std::ifstream inFile;

	inFile.open(fileName);

	if (inFile.is_open())
	{

        while(inFile.eof() != true){

	        inFile >> tempHolder;

            if (InOrder == true){
                if (mainlist.InsertInOrder(tempHolder) == true){

                    std::cout << "Item added to list - with value: " << tempHolder << " . \n";

                } else {

                    std::cout << "Item NOT added to list - with value: " << tempHolder << " . \n";

                }
            } else {


                if (mainlist.Insert(tempHolder) == true){

                    std::cout << "Item added to list - with value: " << tempHolder << " . \n";

                } else {

                    std::cout << "Item NOT added to list - with value: " << tempHolder << " . \n";

                }

            }

            //mainlist.displayList(); for diag

        }   

        std::cout << "end of file\n\n\n\n";

    } else {
	    std::cout << "\n\n###### File Not Found! ######\n\n";   
    }

inFile.close();


}