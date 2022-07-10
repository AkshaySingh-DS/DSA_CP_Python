#include <iostream>
using namespace std;
#include<vector>

// default size is zero, size and capacity both are digfferent size will tell us, the no of elemnts, capacity
//will tell us of how many elemnts are allocated to in a memory.

//once the vector size exausted then new vector is created with size double than the current 
//vector all the elements gets copied from exausted vector to new vector

int main(){

    vector <int> v;

    vector <int> a(5, 1) ;  //a(size, element)

    for (int i : a){
   
    cout << i << " "; 
    }

    cout << endl;
    vector <int> last(a); // copy vector
      for (int i : last){
            cout << i << " "; 
    }

        cout << endl;

    cout <<"Capacity-> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Capacity-> "<<v.capacity()<<endl;

    v.push_back(6);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"size-> " << v.size() << endl;

    cout << "element at 2nd index " << v.at(2) <<endl;

    cout << "front " << v.front() << endl;
    cout << "back " << v.back() << endl;
    //accessing the elements

    for(int i: v){

        cout << i << " " ;
    }
    cout << endl;

    v.pop_back();

    for (int i: v){

        cout << i <<" ";
    } 
    cout << endl;

    //vector empty or not i.e. 0 -> flase , 1 -> true
    cout << v.empty() << endl;

    //1-D array vector initialization with some values
    vector <int> m{4, 2, 1, 7};

    for(int i = 0; i < 4 ;i++){
        cout << m[i] << " ";
    }

    //vector initialization with some diffrent vector by copying 
    cout << endl;
    vector <int> v(m.begin(), m.end());
    for(int i = 0; i < 4 ;i++){
            cout << v[i] << " ";
    }

    //2-D vetor initialization
    vector <vector<int>> m(4, vector<int> (5, 1));

    for(int i = 0; i < 4 ;i++){

        for(int j =0 ; j < 5; j++){
            cout << m[i][j] << " ";
        }
    }

    //2-d false bool array
    vector <vector<int>> m(2, vector<int> (3, false));

    for(int i = 0; i < 2 ;i++){

        for(int j =0 ; j < 3; j++){
            cout << m[i][j] << " ";
        }
        cout << endl; 
    }

     
    return 0;
}