"""
Problem Statement : https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186?leftPanelTab=0
Time complexity : O(N)
space complexity : O(N)
"""
import sys
def getSum(a, b, cy):
    sum = a + b + cy
    val = sum % 10
    cy = sum // 10
    return val, cy
    
def findArraySum(a, n, b, m):
    #Write your code here.
    sum = 0; carry = 0; val = 0
    ans = []
    #define pointers
    i, j = n - 1, m - 1
    #logic for sum
    while i >= 0 and j >= 0:
        val, carry = getSum(a[i], b[j], carry)
        ans.append(val)
        i -= 1
        j -= 1
    
    #let array 'b' exausted then it might get the carry from above
    while i >= 0:
        val, carry = getSum(a[i],0, carry)
        ans.append(val)
        i -= 1
    
    #let array 'a' exausted then it might get the carry from above
    while j >= 0:
        val, carry = getSum(0, b[j], carry)
        ans.append(val)
        j -= 1
    
    #might get carry from above 9999 + 9870 max value of carry could be 9. so while loop is not needed
    if carry:
        ans.append(carry)
    
    return ans[::-1]

if __name__ == "__main__":
    testcases = int(sys.stdin.readline().strip())

    while testcases:
        n, m = map(int, sys.stdin.readline().strip().split())
        arr1 = list(map(int, sys.stdin.readline().strip().split()))
        arr2 = list(map(int, sys.stdin.readline().strip().split()))

        ans = findArraySum(arr1, n, arr2, m)

        for val in ans:
            print(val, end=" ")
        
        print()
        testcases -= 1

"""
CPP Solotion: 
vector <int> getCarrySum(int a, int b, int cy){
    
    vector<int>v;
    
    int sum = a + b + cy;
    int val = sum % 10;
    cy = sum/10;
    v.push_back(val);
    v.push_back(cy);
    return v;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    int i = n - 1, j = m - 1;
    int val, carry = 0;
    vector <int> ans;
    vector <int> sum_carry;
    
    while (i >= 0 and j >=0){
        
        sum_carry = getCarrySum(a[i--], b[j--], carry);
        carry = sum_carry[1];
        ans.push_back(sum_carry[0]);
    }
    
    while (i >= 0){
        
        sum_carry = getCarrySum(a[i--], 0, carry);
        carry = sum_carry[1];
        ans.push_back(sum_carry[0]);
    }
    
     while (j >= 0){
        
        sum_carry = getCarrySum(0, b[j--], carry);
        carry = sum_carry[1];
        ans.push_back(sum_carry[0]);
    }
    
   if(carry)
       ans.push_back(carry);
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}

"""