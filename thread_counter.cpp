/*Author : Brandin Porter
* Date Completed : 03/29/2024
* 
* Credit: GfG. (2023, December 4). Condition variables in C++ multithreading. GeeksforGeeks.
https://www.geeksforgeeks.org/cpp-multithreading-condition-variables/ 

*/

#include <thread> //include the necessary libraries
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std; //standard namespace

mutex mtx; //initialize the mutex object
condition_variable cv; //initalize the condition variable object
bool counter_ready = false; //set counter ready to false

void CountUp() { //count up function
	unique_lock<mutex> lock(mtx); //locks the mutex to only allow the first thread access to i
	for (int i = 0; i <= 20; i++) { //for loop with 20 iterations to count up
		cout << "Counter from thread 1 :" << i << endl; //print each iteration until 20
		if (i == 20) { //when i is equal to 20 the counter ready is set to true
			counter_ready = true;
			cv.notify_one(); //the condition variable notifies the next thread that it is ready
		}
	}
}

void CountDown() { //count down function
	unique_lock<mutex> lock(mtx); //locks the mutex to only allow the second thread access to i
	cv.wait(lock, [] {
		return counter_ready; }); //when counter ready is set to true and cv notifies, the second thread can begin
	for (int i = 20; i >= 0; i--) { //for loop to count down from 20
		cout << "Counter from thread 2 :" << i << endl; //prints each iteration until i = 0
	}
}

int main() { //main function

	thread t1(CountUp); //creates a thread for count up function
	thread t2(CountDown); //creates a thread for count down function

	t1.join(); //joins to make the thread wait for the previous one to complete
	t2.join();

	return 0; //return statement
}

