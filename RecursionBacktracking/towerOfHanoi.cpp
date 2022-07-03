/* 

Problem Statement: https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

You are given the number of discs N. Initially, these discs are in the rod 1. You need to print 
all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the 
total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. 
Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc.
 */

//time complexity : O(2^N) no overlaping sub-problems
//space complexity : O(N)
#include <iostream>
using namespace std;

void towerHanoi(int n, char srcPillar, char helpPillar, char desPillar){

    //base case
    if (n == 0) return;

    //recursive case 
    towerHanoi(n-1, srcPillar, desPillar, helpPillar);

    cout << srcPillar << " --> " << desPillar << endl;

    towerHanoi(n-1, helpPillar, srcPillar, desPillar);
}
/* class Solution{
    public:
        int moves_count;
    
    Solution(){
        moves_count = 0;
    }

    long long toh(int N, int from, int to, int aux) {
        
        //base case 
        if(N == 0) return moves_count;
        
        //rec case
        toh(N-1, from, aux, to);
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        //using class member 
        moves_count++;

        toh(N-1, aux, to, from);
    }

} */

int main(){

    int disks;
    cin >> disks;

    towerHanoi(disks, 'A', 'B', 'C');
    return 0;
}