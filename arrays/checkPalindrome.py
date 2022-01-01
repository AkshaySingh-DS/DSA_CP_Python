"""
Problem statement: 
https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
"""
#approach-1 using O(n) space 
def checkPalindrome(s):
    temp1 = ""
    temp2 = "" 
    for ch in s:
        if ch.isalnum():
            if ch.isalpha():
                temp2 = ch.lower() + temp2
                temp1 += ch.lower()
                
            else:
                temp2 = ch + temp2
                temp1 += ch
                

    if temp1 == temp2:
        return True
    
    return False

#approach - 2 using O(1) 
def checkPalindrome(s):
    start = 0; end = len(s) - 1

    while start < end:
        #check the number is alphanumeric 
        if s[start].isalnum() and s[end].isalnum():
            if s[start].isdigit():
                if s[start] != s[end]:
                    return False
            else:
                if s[start].lower() != s[end].lower():
                    return False
            
            start += 1
            end -= 1
        #skip the steps for non-alphanumeric i.e. special characters
        else:
            if s[start].isalnum() == False:
                start += 1 

            if s[end].isalnum() == False:
                end -= 1  
    
    return True
         

text = input()
print(checkPalindrome(text))

"""
CPP SOLUTION :
bool isValid(char ch){
    
    if((ch >= 'a' and ch <= 'z') || (ch >= 'A' and ch <= 'Z') || (ch >= '0' and ch <= '9'))
        return true;
   
    return false;
}

char toLower(char ch){
    //it handles the intger also
    if((ch >= 'a' and ch <= 'z') || (ch >= '0' and ch <= '9'))
        return ch;
        
    return ch - 'A' + 'a';
}


bool checkPalindrome(string s)
{
    // Write your code here.
   	int start = 0, end = s.length() - 1;

    while (start < end){
        if(isValid(s[start]) and isValid(s[end])){
            
            if(toLower(s[start++]) != toLower(s[end--]))
               return false;             
        }
           
        else{
            
            if(!isValid(s[start]))
                start++;
            
            if (!isValid(s[end]))
                end--;
        }
    }
    return true;
}
"""