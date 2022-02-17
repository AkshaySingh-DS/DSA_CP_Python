/* 
Problem statement : Reverse string using stack
Time Complexity: O(N)
Space Complexity: O(N)

Better approach using two pointer approaching using swapping only in O(N/2) single pass inistead two passes.
*/

#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s){
    stack <char> st;

    //push all characters in stack
    for(auto ch : s){
        st.push(ch);
    }

    //pop all characters from stack and form the string
    string ans;
    while (!st.empty()){
        //ans += st.pop() also works
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << "Input String : " << s << endl;
    cout << "Reverse String :" << reverseString(s);
    return 0;
}