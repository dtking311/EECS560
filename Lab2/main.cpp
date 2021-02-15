
#include "client.h"
#include <string>
#include <fstream>
#include <iostream>


int main(int argc, char** argv){

	 std::string fileName;

	if (argc > 1) {

		fileName = argv[1];

		 Client myClient(fileName); //Basic Ordering
		 myClient.Run();

	 } else {

		 std::cout << "\n\n###### Check Number of Arguments ######\n\n";

	 }

     return 0;
}


/*

todo:

try running on eecs servers

include readme.txt

turn in

*/