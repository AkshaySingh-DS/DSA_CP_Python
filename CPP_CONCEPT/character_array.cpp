#include <iostream>
#include <algorithm>
using namespace std;

//without using typecasting 
int getValue(char ch){

    return ch - '0';
}

//without using built-in function
char toUpperCase(char ch){

    if(ch >= 'A' && ch <= 'Z')
        return ch;
    else
        return ch - 'a' + 'A';
}

//without using built-in function
char toLowerCase(char ch){

        if (ch >= 'a' and ch <= 'z')
        return ch;
    else
        return ch - 'A' + 'a';
}

int getLength(char name []){
    int count = 0 ;
    for(int i = 0;name[i] !='\0'; i++ ){

        count ++;
    }

    return count;
}

bool checkPalindrome(char arr[]) {

    int start = 0, end = getLength(arr) - 1;

    while (start < end){

        if (toLowerCase(arr[start++]) != toLowerCase(arr[end--])){
            return false;
        }

    } 
    return true;
}
void reverseString(char name[]){

    int start = 0, end = getLength(name) - 1;

    while (start < end)
        swap(name[start++], name[end--]);
}
int main(){

    char name[20]; // vector <char> s; then use all properties of vector.

    cin >> name;

    cout << name << endl;

    //name[6] = '\0';

    cout << "reverse string" << endl;
    reverseString(name);
    cout << name;

    cout << toLowerCase('A') << endl;

    cout << toUpperCase('d') << endl;

    return 0;
}