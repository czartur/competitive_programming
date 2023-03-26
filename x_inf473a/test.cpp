#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<string>> vectorVector;
    
    // vectorVector.reserve(2);
    vectorVector.push_back(vector<string>({"artur"})); 
    
    auto& element = vectorVector[0];
    
    cout << vectorVector.capacity() << endl; // 1
    vectorVector.push_back(vector<string>({"second v"}));
    cout << vectorVector.capacity() << endl; // 2 
    vectorVector.push_back(vector<string>({"third v"}));
    cout << vectorVector.capacity() << endl; // 4

    cout << element.size() << endl; // gives a random number (why ?)
    cout << vectorVector[0].size() << endl; // gives 1 (as expected)
}