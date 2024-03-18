/*Author: Brandin Porter
Date Completed: 3/18/2024

Credit: Hu, J. (2024, February 2). How to append text to a file in C++. Delft Stack.
https://www.delftstack.com/howto/cpp/how-to-append-text-to-a-file-in-cpp/#:~:text=To%20append%20text%
20to%20a%20file%20in%20C%2B%2B,Close%20the%20file%20when%20done%20with%20file.close%20%28%29%3B. 

Credit: Ossola, E. (2023, July 17). Reversing a string in C++. DEV Community. https://dev.to/emilossol
a/reversing-a-string-in-c-2kjg#:~:text=To%20reverse%20a%20string%20in%20C%2B%2B%2C%20you%20can,%28%29%20
and%20rend%20%28%29%20functions%20of%20the%20string. 

Credit: Std::Istreambuf_iterator. cplusplus.com. (n.d.). https://cplusplus.com/reference/iterator/istreambuf_iterator/ */


#include <iostream> //include necessary libraries
#include <fstream>
#include <string>

using namespace std; //use standard namespace

int main() { //main function
	string userInput; //initialize user input as a string
	cout << "Enter a sentence to append to a file:"; //prompt to enter a sentence
	getline(cin, userInput); //gets user input

	ofstream myfile("CSC450_CT5_mod5.txt", ios::app); //method to append given file - opens file
	if (myfile.is_open()) { //if the file is open
		myfile << userInput << endl; //writes user input to the file
		myfile.close(); //closes the file
		cout << "Sentence appended to file." << endl; //confirmation message to console

	} else { //if the file didn't open - error message
		cout << "Unable to open file." << endl;
		}

	ifstream infile("CSC450_CT5_mod5.txt"); //declare input file
	ofstream reversedFile("CSC450_CT5_reverse.txt"); //declare and create reverse file
	
	if (infile && myfile) { //if both files are open
		string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>())); //reads the content of the file & turns it into a string

		for (auto it = content.rbegin(); it != content.rend(); ++it) { //for loop - method to iterate in reverse order 
			reversedFile << *it; //writes to reversedfile
		}
		cout << "File reversed." << endl; //confirmation message
	} else{
		cout << " Unable to open files." << endl; //error message
		}
	return 0; //return statement
	}