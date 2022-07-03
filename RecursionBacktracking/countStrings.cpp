

#include <iostream>
using namespace std;

//time complexity: O(2^N) just a variation of fibonacci recurrence in base case 
//can be improved using memoized DP method since having overlapping subproblem
//space complexity:O(N)

int countNonConsiquitive1sString(int n){

    //base case 
    if (n == 0) return 1;
    if(n == 1) return 2;

    //recursive case -> F(N) = F(N-2) '1' '0' ..... (left with n-2 position) + F(N-1) '0'... (left with n-1 position)
    return countNonConsiquitive1sString(n-2) + countNonConsiquitive1sString(n-1);

}
int main(){
    int n;
    cin >> n;

    cout << countNonConsiquitive1sString(n) << endl;
    return 0;
}