#include <iostream>
using namespace std;

bool isStringsEqual(string s1 , string s2){

    int ans = s1.compare(s2);

    if (ans){
        return false;
    }

    return true;
}

int main(){

    //issue of getline after cin
    string name ;
    string course;
    cin >> name;
    getline(cin >> ws, course);
    cout << "Name : " << name << "\nCourse Enrolled : " << course << endl;

    //string assignments
    string name2 = name; 
    cout << name2 << endl;

    //string compare
    cout << isStringsEqual(name, name2) << endl;
    cout << isStringsEqual(name, "Ranu")<< endl;

    //get length in O(1) time.
    cout << course.length() << endl;

    //swap strings
    string s2 = "string2", s1 = "string1";
    cout << "Before swap" << endl;
    cout << s1 << "  " << s2  << endl;
    swap(s1, s2);
    cout << "After Swap" << endl;
    cout << s1 << " " << s2 << endl;

    //get value just like for each
    for (char ch : name){

        cout << ch << "   ";
    }cout << endl;

    //get value using for loop as iterative way
    for(int i = 0; i < name.length(); i++){

        cout << name[i] << " " ;
    }

    return 0;
}