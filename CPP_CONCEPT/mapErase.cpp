#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map <int, int> map;
	
    //first create the key and then append unlike python through an error.
	map[2]++;
	map[4] = 10;
	
	
	//iterating over the key element
	for(auto it: map){
	    
	    cout << it.first <<" "<< it.second << endl;
	}
	
	cout << map.erase(2) << endl;
	//return 1 if key is deleted succ else 0 but not raise an error if key is not found unlike python
	cout << map.erase(2) << endl;
	
	
	for(auto it: map){
	    
	    cout << it.first <<" "<< it.second << endl;
	}
	
	
	return 0;
}