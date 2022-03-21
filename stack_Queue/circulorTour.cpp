/* 
Problem Statement : https://practice.geeksforgeeks.org/problems/circular-tour/1
or 
https://www.codingninjas.com/codestudio/problems/find-the-first-circular-tour-that-visits-all-the-petrol-pumps_799923

Using Approach-3
Time Complexity: O(N)
Space Complexity: O(1)

Approach-1 : Using two loops brute force time -> O(N^2), space-> O(1)
Approach-2 : Using Queue Data structure time -> O(N), space-> O(1) will use given array as a queue
Approach-3 : Using Deficit variable, that will help to not visit already visired petrol pumps
*/

#include <iostream>
using namespace std;

struct petrolPump{

    int petrol;
    int distance; 
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i = 0; i < n; i++){
           
           //travel possible then keep on traversing next wothout affecting start
           balance += p[i].petrol - p[i].distance;
           
           //if not possible means balance is -ve
           if(balance < 0){
               
               //not possible to traverse from prev start to i hence update start now 
               start = i + 1;
               
               //get how much defficiency we got
               //deficit = balance won't work we have to add all the deficiency came in between 
               deficit += balance;
               //and alsp reset the balance
               balance = 0;
       }
    }
    
    //we are adding it since deficit will be in -ve
    return deficit + balance >=0 ? start: -1;
        
    }
};

//using queue
int tour(petrolPump p[],int n)
    {
       int start = 0;
        int end = 1;
        int bal = p[start].petrol - p[start].distance;
        
        while (start != end || bal < 0){
            
            // dequeue 
            while (bal < 0 && start != end){
                
                bal -= p[start].petrol - p[start].distance;
                
                start = (start +1) % n;
                
                if (start == 0)
                    return -1;
            }
            
            //enqueue
            bal += p[start].petrol - p[start].distance;
            end = (end + 1) % n;
        }
        
        return start;
        
}