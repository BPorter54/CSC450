/*Author: Brandin Porter
Date Completed: 03/04/2024
Credit: GfG. (2022, October 18). New and delete operators in C++ for Dynamic Memory.
GeeksforGeeks. https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/ 
*/


#include<iostream> //include iostream class library

using namespace std; //use standard namespace

int main() {
	int int1, int2, int3; //initialize variables for each int

	cout << "Enter your first integer: "; //prompt for first int
	cin >> int1; //assign user inpit to int1

	cout << "Enter your second integer: "; //prompt for second int
	cin >> int2; //assign user inpit to int2

	cout << "Enter your third integer: "; //prompt for third int
	cin >> int3; //assign user inpit to int3

	int* ptr1 = new int; //new operator to initialize pointers
	int* ptr2 = new int;
	int* ptr3 = new int;

	*ptr1 = int1; //assign pointers to variables
	*ptr2 = int2;
	*ptr3 = int3;


	cout << "Memory address of integer 1: " << ptr1 << endl;  //print address-of operators
	cout << "Memory address of integer 2: " << ptr2 << endl;
	cout << "Memory address of integer 3: " << ptr3 << endl;
	cout << "---------------------------------" << endl;
	cout << "Value of integer 1: " << *ptr1 << endl; //print the actual value of each operator
	cout << "Value of integer 2: " << *ptr2 << endl;
	cout << "Value of integer 3: " << *ptr3 << endl;
		
	delete ptr1; //delete operators for each pointer o
	delete ptr2;
	delete ptr3;

	return 0; //return statement

}