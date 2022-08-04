#include <iostream>
#include <queue>

using namespace std;

//based on FIFO data structure ->  front (deletion) and rear(insertion)
//time complexity insertion/ deletion O(1) time.
int main(){

    queue <string> q;

    //q.push() for insretion at rear, q.pop() for deletion at front. 
    //insertion from rear
    q.push("Manu");
    q.push("Akshay");
    q.push("Singh");
    q.push("CPP");

    cout << "Get Size of Queue : " << q.size() << endl;
    cout << "Get Front : " << q.front() << endl;
    cout << "Get Rear : " << q.back() << endl;

    //deletion from front
    q.pop();

    cout << "After deletion of queue Get Front : " << q.front() << endl;

    cout << "size after pop : " << q.size() << endl; 

    q.pop();
    q.pop();
    q.pop();

    if (q.empty()){
        cout << "Queue is  empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
    return 0;
}