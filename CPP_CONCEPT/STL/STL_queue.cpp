#include <iostream>
#include <queue>

using namespace std;

//based on FIFO data structure ->  front (deletion) and rear(insertion)
//time complexity insertion/ deletion O(1) time.
int main(){

    queue <string> q;

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
    return 0;
}