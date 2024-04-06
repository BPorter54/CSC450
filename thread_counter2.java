/* Author: Brandin Porter
 * Date Completed: 04/06/2024
 * Credit: Jha, P. (2023, January 21). Synchronization, locks, conditional variables in Java. Medium. 
 * https://medium.com/@jhaprincet/synchronization-locks-conditional-variables-in-java-b0c3413fd28e */

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CountThread { //count thread class to declare locks and conditions
    private static Lock lock = new ReentrantLock(); //creates a lock object
    private static Condition threadFinished = lock.newCondition(); // creates a condition for the next thread to start
    private static int count = 0; //set count to 0
    private static boolean threadUpFinished = false;
    
	public static void main(String[] args) { //driver class
        Thread t1 = new Thread(() -> { //creates the first thread to count up
            threadUp(); //performs thread up function
        });

        Thread t2 = new Thread(() -> { //creates second thread to count down
            threadDown(); //performs thread down function
        });

        t1.start(); //signals the threads to start
        t2.start();
    }

   private static void threadUp() { //thread up function
        lock.lock(); //locks the thread to be able to access resources "i" and the boolean
        try {
            for (int i = 0; i <= 20; i++) { //for loop with 20 iterations to count up from 0
                System.out.println("Thread 1 Counter: " + i); //prints message for each iteration
                count = i; //sets the count variable to i
            }
            
            threadUpFinished = true;  //sets condition variable to true
            threadFinished.signal(); //signals the waiting thread that threadUp is finished
            
        } finally {
            lock.unlock(); //unlocks the lock
        }
    }
   private static void threadDown() { //thread down function 
    	lock.lock(); //locks the thread to be able to access resources
        try {
        	while (!threadUpFinished) { //while the threadUpFinished condition is still false, wait
        threadFinished.await();
        	}
            for (int i = count; i >= 0; i--) { //for loop with iterations to count from 20 to 0
                System.out.println("Thread 2 Counter: " + i); //prints message for each iteration
            }
        	} catch (InterruptedException e) { //exception when interrupted inactive
        		e.printStackTrace();	
        } finally {
            lock.unlock(); //unlocks the lock
        }
      }
   }
