/*
Problem Statement :  Given a “4 x n” board and tiles of size “4 x 1”, 
count the number of ways to tile the given board using the 2 x 1 tiles. 
Note: A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 
*/


//time complexity: O(2^n) can be imprived further using memoization DP
//space complexity: O(n)
#include <iostream>
using namespace std;
int findWaysToFillTiles(int n){

    //base case 
    if (n <= 3) return 1; //understand about n->0 condition why it is 1.(by taking e.g. 4*4 Board)

    //rec case (Recurrence similar to fibonacci)
    int v_ways = findWaysToFillTiles(n-1);
    int h_ways = findWaysToFillTiles(n-4); // if n>=4 then only apply for horizontal tiles.
    return h_ways + v_ways;

}

int main(){

    int n;
    cin >> n;
    cout << findWaysToFillTiles(n) << endl ;
    return 0;
}