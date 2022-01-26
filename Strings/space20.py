"""
Problem Statement: replace all the spaces with %20
Time Complexity: O(N)
space complexity : O(1)
Follow up : O(1) extra space same as reverseSpace module.
"""

def fill_space(para):
    """
    will not work for multiple spaces
    para1 = para.split()
    return '%20'.join(para1)
    """
    #will not replace spaces inplace, instead return the new string
    return para.replace(" ", "%20")



if __name__== "__main__":

    para = "I am   akshay   singh"
    print(fill_space(para)) 
    print()
"""
CPP SOLUTON:
string fillSpace(string str){
    
    string ans;
    for(int i = 0 ;i < str.length(); i++){
        
        if (str[i] == ' '){
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        }
            
        else{
            ans.push_back(str[i]);
        }
    }
    
    return ans;

    //also possible in O(1) space we have to resize the string 
    
}
"""