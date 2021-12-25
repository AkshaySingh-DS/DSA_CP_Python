#include <iostream>
#include <map>

/*
implementation of map:
-> This is an ordered map
-> implemented over Red Black tree
-> find, insert, delete all operations takes O(log N) time.
-> Quite slow than unordered map -> (implementation over hashMap) 
-> keys always be sorted but in python orderedDict is maintain the order in which the keys were inserted
*/
using namespace std;

int main(){

    map <int, string> m;
    m[1] = "Akshay";
    m[2] = "Singh";
    m[3] = "Python";
    m[5] = "CPP";

    //m.insert( {4, "Manu"});

    for (auto i : m){

        cout << i.first << " " << i.second << endl;
    }

    cout << "find element 5  ? " << m.count(5) << endl;

    m.erase(5);

    for (auto i : m){

        cout << i.first << " " << i.second << endl;
    } 

    //return the refrence iterator;
    auto it = m.find(3);

    for(auto i = it ; i != m.end(); i++){

        //*i derefrencing
        cout << (*i).first << endl;

    }

    return 0;

}