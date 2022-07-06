/* problem Statement: 
https://practice.geeksforgeeks.org/problems/subsets-1613027340/0/?category[]=Backtracking&category[]=Backtracking&page=1&query=category[]Backtrackingpage1category[]Backtracking
 */
#include <iostream>
using namespace std;

//time and space complexity: O(2^N) and O(N) where N is the size of given string/array. 
void powerSets(string s, string output, int i){

    //base case
    if(i == s.length()){
        cout << output << endl;
        return;
    } 

    //rec case
    output.push_back(s[i]);//including the ith character
    powerSets(s, output, i + 1); 

    //remove the previously added character--> backtracking 
    output.pop_back();//excluding the ith character
    powerSets(s, output, i + 1);


    /* above steps can be reduced using below code.
    powerSets(s, output + s[i], i+1)
    powerSets(s, output, i+1) */

}


int main(){

    string str ;
    cin >> str;

    powerSets(str, "", 0);
    return 0;
}