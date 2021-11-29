"""
problem Statement:

https://www.codechef.com/problems/HMAPPY
TIME COMPLEXITY : O(log(max(Bi)*max(Ai))) * O(N)
"""
def good(maxcan, n, m, balls, cand):

    cntballons = 0
    for i in range(n):
        #ballons[i]-> number of baloons that Appy want on ith day
        #mid(maxcan)/cand[i] -> represent the candies that 
        #compesnate with balloons means ->number of balloons that I can give on ith day
        #reperesents the number of ballons on the ith day
        ball_Onday = balls[i] - (maxcan// cand[i])
        
        cntballons += max(0, ball_Onday)
        
        if cntballons > m:
            return False

    #we can satisfies appy requirements of ballons(we have enough number of balloons) then minimize max candies further
    return True 

def minCandiesAppy(n, m, balloons, candies):
    left = 0 
    right = 0 

    #we can also do right = max(ballons) * max(candies) but that won't be the tightest one
    for i in range(n):
        temp = balloons[i] * candies[i]
        if temp > right:
            right = temp
    
    ans = 0

    #logic
    while left <= right:
        mid = (left + right) //2
        if good(mid, n, m, balloons,candies):
            ans = mid
            right = mid - 1
        else:
            left = mid + 1 
    
    return ans


def main():
    n, m = map(int, input().split())
    balloons = list(map(int, input().split()))
    candies = list(map(int, input().split()))
    #invoking
    print(minCandiesAppy(n, m, balloons, candies))

if __name__ == "__main__":
    main()

"""
CPP Solution:
#include <bits/stdc++.h>
using namespace std;
#define LL long long


bool good(LL mid, LL n, LL m, LL *bal, LL *candn){
    
    LL cntballons = 0, ballonsOn_Day;
    
    for(LL i = 0 ; i < n; i++){
        
        ballonsOn_Day = bal[i] - (mid/candn[i]);
        
        if (ballonsOn_Day >= 0){
            cntballons += ballonsOn_Day;
        }
        
        if (cntballons > m)
            return false;
    }
    
    return true;
}

int main()
{
    LL n, m;
    cin >> n >> m;
    LL balloons[n], candies[n];
    
    for(LL i = 0; i < n; i++){
        cin >> balloons[i];
    }
    
    for(LL i = 0; i < n; i++){
        cin >> candies[i];
    }

    LL left = 0, right = 0, temp;
    
    for (LL i = 0; i < n; i++){
        temp = balloons[i] * candies[i];
        
        if (temp > right)
            right = temp;
    }
    
    
    // logic
    LL mid, ans = 0 ;
    while (left <= right){
        
        mid = left + (right-left)/2;
     
        if (good(mid, n, m, balloons, candies)){
            
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}

"""