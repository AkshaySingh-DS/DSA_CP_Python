#include <iostream>
#include <queue>

using namespace std;


// time complexity of building heap O(n)
// time complexity to retrieve max/min i.e. root element is O(1)
// time complexity of deleting root O(log n)
// time complexity for insertion O(log N)
// time complexity for search random element O(log N)
int main(){

    //max heap
    priority_queue <int> maxHeap;

    //push element in max-heap
    maxHeap.push(5);
    maxHeap.push(0);
    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(6);

    int size = maxHeap.size();

    cout << "Elements in heap are : ";
    for(int i = 0; i < size; i++){

        cout << maxHeap.top() << " ";

        //delete the maxElement from heap
        maxHeap.pop();
    }

    cout << endl;

    cout << "is Heap empty ? : "<< maxHeap.empty() << endl;

    //min heap
    priority_queue <int, vector<int>, greater<int> > minHeap;

    //push element in max-heap
    minHeap.push(5);
    minHeap.push(0);
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(6);

    size = minHeap.size();
    cout << "Elements in Max - Heap are : ";
    for(int i = 0; i < size; i++){

        cout << minHeap.top() << " ";

        //delete the maxElement from heap
        minHeap.pop();
    }

    cout << endl;
    cout << "is Min - Heap empty ? : "<< maxHeap.empty() << endl;
    return 0;
}