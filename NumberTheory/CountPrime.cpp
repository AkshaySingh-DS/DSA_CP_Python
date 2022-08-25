/* 
Problem: https://leetcode.com/problems/count-primes/
 */

#include<iostream>
#include<vector>

using namespace std;


//below code givsd TLE
class Solution {
public:
    //time complexity of below isPrime function -> O(root(n))
    bool isPrime(int x){
        
        for(int i = 2 ; i * i <= x; i++){
            
            if(x % i == 0) return false;
        }
        
        return true;
    }
    
    //time complexity of below entire function -> O(root(n) * n)
    int countPrimes(int num) {
        
        int cnt = 0;
        
        for(int i = 2; i < num; i++){
            if(isPrime(i)) cnt++;
        }
        return cnt;
    }
};

//Using SeiveOfErastothenes 
class Solution2{
public:
    int countPrimes(int num) {
        
            //map is a vector where ith index represents whether i is a prime.
            vector<bool> map(num + 1, true);

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
            
            //now count all primes which is smnaller than given number
            int cnt = 0;
            for(int i = 0; i < num; i++){
                
                if(map[i]) cnt ++;
            }
        
        return cnt;
        }
};