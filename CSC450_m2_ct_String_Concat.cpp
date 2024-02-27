/*Author: Brandin Porter
Assignment completed: 2/26/24
Credit: GfG. (2023, October 9). Strings in C++. GeeksforGeeks. https://www.geeksforgeeks.org/strings-in-cpp/ */

#include<iostream> //include iostream class
#include<string> //include string class

using namespace std; //use the standard namespace

int main() { //main function
	for (int i = 0; i < 3; ++i) { //for loop to ask for two strings three different times
		string firstString, secondString; 

		cout << "Enter your first string: "; //print string1 message
		getline(cin, firstString); //retrieve user input, assign to firstString


		cout << "Enter your second string: "; //print string2 messaqe
		getline(cin, secondString); //retrieve user input, assign to secondString

		string concatenated = firstString + " " + secondString; //concatenate the strings using "+"

		cout << "The concatenated string is: " << concatenated << endl; //prints message along with the concatenated string
		cout <<	"-----------------------------------------------" << endl; //line to separate the three different loops
	}
	return 0; //return statement