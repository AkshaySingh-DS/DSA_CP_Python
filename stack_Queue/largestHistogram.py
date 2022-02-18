"""
Problem Statement : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
Time Complexity: O(N)
Space Complexity: O(N)

Approach using the two stack.
"""

class Solution(object):
    def nearestLeft(self, arr, size):
        #this steps help us to pop element from stack after for loop
        nleft = [0] * size
        stack = []

        for prev in range(size-1, -1, -1):
            #when stack is not empty and prev element is small than stack.top
            
            while stack and arr[prev] < arr[stack[-1]]:
                nleft[stack[-1]] = prev+1
                stack.pop()

            stack.append(prev)
        
        #it'll return the nerset max left
        return nleft
    
    
    def nearestRight(self, arr, size):
        #this steps help us to pop element from stack after for loop
        nright = [size-1] * size
        stack = []
        
        for next in range(size):

            #when stack is not empty and next element is small than stack.top
            while stack and arr[next] < arr[stack[-1]]:
                nright[stack[-1]] = next - 1
                stack.pop()

            stack.append(next)

        #it'll return the nerset max right
        return nright
    
    def largestRectangleArea(self, heights):
        size = len(heights)
        #get the nearest maximum at left
        left = self.nearestLeft(heights, size)
        #print(left)
        
        #get the nearest maximum at right
        right = self.nearestRight(heights, size)
        
        #print(right)
        max_area = 0
        for i in range(size):
            area = heights[i] * (right[i] - left[i] + 1)
            max_area = max(max_area, area)

        return max_area