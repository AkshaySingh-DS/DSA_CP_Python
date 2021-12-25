#include <iostream>
#include<list>

using namespace std;

// STL has the implementation of doubly linked list 
//time complexity -> insertion deletion takes O(N) time.
int main(){

    list <int> dl;

    cout << "cirrent size " << dl.size() << endl;

    //5 elemets initialization with value as 100.
    list <int> dll(5, 100);

    cout << "cirrent size " << dll.size() << endl;

    cout << "elements in list are: ";
    for (int i : dll){

        cout << i << " ";
    }
    cout << endl;

    //insertion  from both ends
    dl.push_front(10);
    dl.push_front(21);
    dl.push_back(12);
    dl.push_back(10);

    cout << "cirrent size " << dl.size() << endl;

    for (int i : dl){

        cout << i << " ";
    }
    cout << endl;

    //element cant be fetched from indexing since this is is linked list

    //deletion 
    dl.erase(dl.begin());

    cout << "After front elemrnt deletion :";

    for (int i : dl){

        cout << i << " ";
    }
    cout << endl;

    //check deque empty or not 0-> false 1 -> true
    cout << "is list empty: " << dl.empty() << endl;

    return 0;
}