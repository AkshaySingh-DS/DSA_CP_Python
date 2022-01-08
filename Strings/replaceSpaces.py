"""
Problem Statement: https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?leftPanelTab=3

Time complexity : O(N), n length of given string
Space Complexity : O(N) folloup O(1)
"""
def replaceSpaces(str):
    # Write your code here.
    text = ""
    
    for ch in str:
        if ch.isspace():
            text += "@40"
        else:
            text += ch
            
    return text


"""
CPP Solution:
O(N) : space complexity
bool isSpace(char ch){
    
    if (ch == ' ')
        return true;
    
    return false;
}

string replaceSpaces(string &str){
	// Write your code here.
    string ans = "";
    for(char ch : str){
        
        if (isSpace(ch)){
            ans += "@40";
        }
        else
            ans += ch;
    }
    return ans;
}

O(1) Space Complexity:

string replaceSpaces(string &str){
	// Write your code here. inplace solution
    int len = str.length() - 1;
   	int cnt = 0;
    
    //getspaces count
    for(char ch : str){  
        if (ch == ' ')
            cnt += 1;    
    }
    
    // new len would be-> let say 1 space cover @ rest 2 will be left (40) for this get all extra space. 
    int newLen = len + cnt * 2;
    
    //last one for null character, resize the string inplace.
    str.resize(newLen + 1);
    
    // take advantage of extra memory that we have created in-place 
    while(newLen){
        
        //if space not found 
        if (str[len] != ' ')
            str[newLen--] = str[len];
 
        //if space found put the character, 04@ sequence bcoz we are putting from backwards. 
        else{
            str[newLen--] = '0';
            str[newLen--] = '4';
            str[newLen--] = '@'; 
        }  
        len--;
    }
   	return str;
}
"""

