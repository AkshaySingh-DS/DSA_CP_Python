#include <iostream>
#include<vector>
#include <unordered_map> //use this
using namespace std;

/*
implementation of map:
-> This is an un-ordered map
-> implemented over Hash Map.
-> find, insert, delete all operations takes O(1) average time.(if hash map is little complex than might take more)
*/


int main(){

    //key will be of string type and mapped value will
    // be of double type(first type for key , second type for value)
    unordered_map<string, double> umap;
 
    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    //insert value by insert function
    umap.insert(make_pair("e", 2.718));
    
    //traversing map by key and value
    for(auto x : umap){

        cout << x.first <<" "<< x.second << endl;
    }

    //search key using find iterator end is returned if key not found.
    if (umap.find("PI") != umap.end())
        cout << "key found" << endl;

    if (umap.find("PIO") == umap.end())
        cout << "key not found" << endl;    

    //get size 
    cout << umap.size() << endl;

    //to check unordered map is empty or not
    //unordered_map<string, double> umap2;
    if (umap.empty()){
        cout << "empty map";
    }
    else{

        cout << "not empty" ;
    } cout << endl;

    //delete element using erase by key/iterator/range

    umap.erase("root2");
    umap.erase(umap.find("loge"));

    cout << "\nTwo keys are deleted\n";
    //traversing map by key and value
    for(auto x : umap){

        cout << x.first <<" "<< x.second << endl;
    }


    return 0;
}
