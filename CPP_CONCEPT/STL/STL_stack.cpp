#include <iostream>
#include<stack>

using namespace std;
// based on LIFO -> Last in First out
//time complexoty for insert, delete, top is O(1)

int main(){

    stack <string> s;

    s.push("Akshay");
    s.push("singh");
    s.push("CPP");
    s.push("Pyhton");

    cout << "CURRENT TOP ELEMENT : " << s.top() << endl;

    s.pop();

    cout << "CURRENT TOP ELEMENT : " << s.top() << endl;

    cout << "Size of stack : " << s.size() << endl;

    // 0-> flase and true -> 1
    cout << "Check stack empty? : " << s.empty() << endl;


    return 0;
}