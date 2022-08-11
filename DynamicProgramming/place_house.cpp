/* Probelem Statement: There is a street with n * 2 plots, where there are n plots on each side of the 
street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.
Return the number of ways houses can be placed such that no two houses are adjacent to each other on 
the same side of the street. Since the answer may be very large, return it modulo 109 + 7.
Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on 
the ith plot on the other side of the street.

problem link: https://leetcode.com/problems/count-number-of-ways-to-place-houses/

*/
#define MOD 1000000007
class Solution {
public:
    
    //Bottom UP DP with space optimization 
    //Time Complexity : O(N) where N is no of plots, SPACE Complexity : O(1)
    int countHousePlacements(int n) {
        int prev2 = 2;
        int prev1 = 3;
    
        //solving the problem for one side of street
        if(n == 1) return prev2 * prev2; 
        if(n == 2) return prev1 * prev1;

        int ways;
        for(int i = 3; i < n + 1; i++ ){
            
            ways = (prev1 + prev2) % MOD;
            prev2 = prev1 ;
            prev1 = ways;
        }

        //no of combinations with second side since both sides are independent to each other i.e. ways * ways
        return ((ways % MOD) * (ways % MOD)) % MOD;
    }
};