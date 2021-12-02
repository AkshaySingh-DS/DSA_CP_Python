"""Problem Statement :
https://www.spoj.com/problems/PRATA/

Time complexity: Let R max rank then time taken by R to make all Prata -> k and numbers of cooks let say c, then c * log(k) would be the time

IMPORTANT ARTICLE TO TAKE COMPLEX INPUTS IN PYTHON IN CP: 
https://levelup.gitconnected.com/basic-input-and-output-techniques-used-in-competitive-programming-5be5622b4525
"""
def good(currentmintime, p, cooks, ranks):
    #prata made initially
    pratcnt = 0

    #logic to be good mid 
    for i in range(cooks):
        t = 0; j = 1
        while True:
            t = t + (j * ranks[i])
            j += 1
            if currentmintime < t:
                break
            pratcnt += 1

    #return True if they are able to make  prta >= p
    return pratcnt >= p

def minTimeforPrata(p, cooks, ranks, maxRanks):
    left = 0 ; ans = 0

    #calculate search space by getting the cook who is taking max time.
    right = 0
    cnt = 0; i = 1
    while cnt < p:
        right = right + (i * maxRanks)
        cnt += 1
        i += 1

    #binary search logic to reduce time

    while left <= right:
        mid = (left + right)//2

        if good(mid, p, cooks, ranks):
            #if mid time is good enough then minimize it further
            ans = mid
            right = mid - 1
        else:
            left = mid + 1

    return ans
        
def main():
    test_cases = int(input())
    for _ in range(test_cases):
        p = int(input())
        cooks, *ranks = input().split()
        cooks = int(cooks)
        ranks = list(map(int, ranks))
        maxRanks = max(ranks)
        print(minTimeforPrata(p, cooks, ranks, maxRanks))

if __name__ == "__main__":
    main()

"""
CPP Solution:
#include <iostream>
using namespace std;
bool good(inta mintime, int p, int cooks, int * ranks){
    
    int partcnt = 0;
    
    //logic 
    for(int i = 0; i < cooks; i++){
         int t = 0, j = 1;
         
         while (true){
             
             t = t + (ranks[i] * j);
             j++;
             
             if (mintime < t){
                 break;
             }
             
             partcnt ++;
         }
    }
    return (partcnt >= p);
}
int minTimeForPrata(int p, int cooks, int * ranks, int maxRanks) {
    //search space 
    int left = 0;
    int right = 0;
    int j = 1;
    for(int cnt = 0; cnt < p; cnt++){
        
        right = right + j * maxRanks;
        j++;
    }
    
    //binary search logic
    int mid, ans = 0 ;
    while(right >= left){
        
        
        mid = (left) + (right-left)/2;
        
        if (good(mid, p, cooks, ranks)){
            
            //reduce time 
            
            ans = mid;
            right = mid -1;
        }
        else{
            
            left = mid + 1;
        }
    }
    
    return ans;
}
int main() {
	int t;
	int p, cooks;
	
	std::cin >> t;
	for(int i = 0; i < t; i++){
	    
	    cin >> p ;
	    cin >> cooks;
	    int ranks[cooks], maxRanks = 0;
	    
	    for(int i = 0; i < cooks; i++){
	        
	        cin >> ranks[i];
	        maxRanks = max(maxRanks, ranks[i]);
	    }
	    
	    std::cout << minTimeForPrata(p, cooks, ranks, maxRanks) << std::endl;
	}
	
	return 0;
}
"""