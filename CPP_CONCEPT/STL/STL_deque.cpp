#include<iostream>
#include<deque>
using namespace std;

//in deque data structure data can be inserted from front and back and similarlary can 
//be deleted from front and back

//size of dec will get decrease after deletion but max_size wont change it will be same as it was previous before deletion

//each insertion and deletion takes O(1) time.
int main(){

    deque <int> d;

    //insertion
    d.push_back(20);
    d.push_back(24);

    d.push_front(10);

    d.push_back(33);

    for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;

    //front and back element
    cout << "front element -> " << d.front() <<endl;
    cout << "back element ->  " << d.back() <<endl;

    //random indexing using 'at'
    cout << "First index and second index elements -> " << d.at(1) << " " << d.at(2) << endl;

    //get size
    cout << "current size " << d.size() << endl;

    //deeltion from both ends
    cout << "Before Deletion " << endl ;
    for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;

    cout << "After Deletion of back element " << endl ;

    d.pop_back();
    for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;

    cout << "current size " << d.size() << endl;
    cout << "After Deletion of front element" << endl ;
    
    d.pop_front();
    for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;

    cout << "current size " << d.size() << endl;

    //delete part of the deque
    d.push_back(43);

     for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;

    cout << "Current Size" << d.size() << endl;
    //from where to where we want to delete i.e. delete first two elements
    d.erase(d.begin(), d.begin()+ 2);

    cout << "Current Size " << d.size() << endl;

    //check deque empty or not 0-> false 1 -> true

    cout << d.empty() << endl;

    for (int val : d){

        cout << val <<" " ;
    
    }
    cout << endl;


    return  0;
}