/* 
Problem : https://leetcode.com/problems/ugly-number/  
*/

#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

//Using Seive of Erastothenes gives TLE
//Time Complexity : O(N), Space complexity : O(N)
class Solution {
public:
    bool isUgly(int num) {
        //edge cases
        if(num == 1) return true;
        if (num <= 0) return false;
        
        //map is a vector where ith index represents whether i is a prime.
        vector<bool> map(num+1, true);

        //making all even's indices as a non prime 
        for(int i = 0; i < num+1; i+=2) map[i] = false;
    
        //except 2 
        map[1] = false; map[2] = true;

        //now only odd numbers which can be primes so will check only those
        int i = 3;
        while (i * i <= num){
            
            //if map[i] -> true which means its an odd and it is a prime hence making all of its factor as non prime
            if (map[i]) {

                for(int j = i*i; j < num + 1; j+= 2*i) map[j] = false;
            }
            i += 2; //now checking next odd 
        }
        //set with 2, 3, 5 prime numbers
        unordered_set <int> s({2, 3, 5});
      

        for(int i = 1; i < num+1 ; i++){
            
            //if i is prime and that not in set {2, 3, 5} then it must not divide given num if so then it would be ugly   
            if(map[i] == true and s.find(i) == s.end()){

                if(num % i == 0) // i -> prime other then 2,3,5
                    return false;
            }
        }
        return true;  
    }
};


class Solution1 {
public:
    //Time complexity : O(log2(N))
    //Auxillary Space -> O(log2(N)) Recursive Stack
    bool solveUgly(int n){
        //base case
        if(n == 1) return true;
        
        bool bool_2, bool_3, bool_5;
        bool_2 = bool_3 = bool_5 = false;
        
        if(n % 2 == 0)
             bool_2 = solveUgly(n/2);
        
        else if(n % 3 == 0)
            bool_3 = solveUgly(n/3);
        
        else if (n % 5 == 0)
             bool_5 = solveUgly(n/5);
        
        return bool_2 or bool_3 or bool_5;
        
        //if num and its all factors can not be divisible by 2 and 3 and 5 hence number is a prime with other factor than {2, 3, 5}, Hence not be ugly
        
    }
    bool isUgly(int num) {
        
        //edge case
        if(num <= 0 ) return false;
        return solveUgly(num);
    }
};