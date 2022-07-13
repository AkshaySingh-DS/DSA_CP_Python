#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	
    //for 1-d set
	set<int> s;
	s.insert(2);
	s.insert(2);
	s.insert(1);
	s.insert(9);
	s.insert(1);
	
	for(auto val : s){
	    cout << val << " ";
	}
	cout << endl;

	vector<int> items;
	items.push_back(1);
	items.push_back(9);
	items.push_back(90);
	
	for(auto val: items){
	    if (s.find(val) == s.end())
	        cout << "not found " << val << endl;
	    else {
	        cout << " found element " << val << endl;
	    }
	}

    //for 2d-set
    set <vector<int>> z;
	vector <vector<int>> k;
	
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	
	z.insert(v);
	k.push_back(v);
	
	v.clear();
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	z.insert(v);
	k.push_back(v);
	
	v.clear();
	v.push_back(20);
	v.push_back(3);
	v.push_back(1);
	k.push_back(v);
	
	for(vector<int> v : k){
	    if (z.find(v) == s.end())
	        cout << "not found " << endl;
	    else {
	        cout << "found element" << endl;
	    }
	}
	return 0;
}