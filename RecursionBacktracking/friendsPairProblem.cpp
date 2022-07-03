/* 
Problem Statement: https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1 

Given N friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends 
can remain single or can be paired up.

Based on principle of inclusion-exclusion:
if there are n persons and Person 'A' has a right to choose 1 out of N-1 persons that would be (N-1)C.1 ways. he can choose.
*/

//time complexity: O(2^n) just like fibonacci (Can be reduced using memoized DP)
//space complexity:O(n)

#include <iostream>
using namespace std;

int findNoOfWaysToPairNfriends(int n){

    //base case
    if(n == 1 or n == 0) return 1;

    //rec case
    //principle of Exclusion-Inclusion (if the work is not yet completed keep multiplying) --> (n-1)C1 * findNoOfWaysToPairNfriends(n-2)
    int count = findNoOfWaysToPairNfriends(n-1) + (n-1) * findNoOfWaysToPairNfriends(n-2);
    return count;

}
int main(){
    int n;
    cin >> n;

    cout << findNoOfWaysToPairNfriends(n) << endl;
    return 0;
}

