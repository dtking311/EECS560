#include "client.h"
#include "student.h"
#include <string>
#include <fstream>
#include <iostream>

void Client::Run(){
while(true) { 



	int userInput = 0;

    std::cout << "________________________________________________";
    std::cout << "\nChoose one operation from the options below:\n\n"

                 "1) AddStudent\n"
                 "2) RemoveStudent\n"
                 "3) PrintStudentList\n"
                 "4) FindStudent\n"
                 "5) Exit\n";
    std::cout << "________________________________________________\n\n";

    std::cin >> userInput; //check for invalid case here!!!!!!!


switch (userInput) {
    case 1:
    {   
        int userInput1_1 = 0;
        std::string userInput1_2 = "";

        std::cout << "---Add a new student---\n\nEnter student ID number: ";
        std::cin >> userInput1_1;

        std::cout << "\nEnter student name: ";
        std::cin >> userInput1_2;

        if(mainTable.AddEntry(userInput1_1, userInput1_2) == true){

            std::cout << "\n\nStudent has been inserted!\n";
        } else {

            std::cout << "\n\nStudent was not inserted into the list\n";

        }
        
        break;
    }
    case 2:
    {
        
        std::string userInput2_1 = "";

        std::cout << "---Remove a new student---\n\nEnter a student name to remove: ";
        std::cin >> userInput2_1;


        if(mainTable.RemoveEntry(userInput2_1) == true){

            std::cout << "\n\nStudent has been removed!\n";
        } else {

            std::cout << "\n\nStudent was not deleted because they could not be found in the list!\n";

        }


        break;
    }
    case 3:
    {
        mainTable.PrintEntryList();
        
        break;
    }
    case 4:
    {
        std::string userInput4_1 = "";

        std::cout << "---Find a student---\n\nEnter a student name to find: ";
        std::cin >> userInput4_1;

        mainTable.Output_FindEntry(userInput4_1);
        break;
    }
    case 5:
    {
        return;
        break;
    }

    default:
    {
        break;
    }

}
}
}




Client::~Client(){	//destructor

	//delete[] allRecords;

}	




Client::Client(std::string fileName){

std::string tempHolder1 = "";
std::string tempHolder2 = "";
int idNumber = 0;


std::ifstream inFile;

	inFile.open(fileName);

	if (inFile.is_open())
	{

        while(inFile.eof() != true){

	        inFile >> tempHolder1;
            inFile >> tempHolder2;

            if(tempHolder1.length() != 0);
            tempHolder1.pop_back();

            //if(tempHolder2.length() != 0){
                if(tempHolder2.back() == ',')
                tempHolder2.pop_back();
            //}

            idNumber = stoi(tempHolder1);
            std::cout << "\nReading from file: " << idNumber << " - " << tempHolder2 << "\n";

            
                if (mainTable.AddEntry(idNumber, tempHolder2) == true){

                    std::cout << "Item added to list - with value: " << idNumber << ". \n";

                } else {

                    std::cout << "Item NOT added to list - with value: " << idNumber << " . \n";

                }

        }   

        std::cout << "end of file\n\n\n\n";

    } else {
	    std::cout << "\n\n###### File Not Found! ######\n\n";   
    }

inFile.close();

}