#include <bits/stdc++.h>
using namespace std;

int main(){
    // vector<vector<string>> vectorVector;
    
    // // vectorVector.reserve(2);
    // vectorVector.push_back(vector<string>({"artur"})); 
    
    // auto& element = vectorVector[0];
    
    // cout << vectorVector.capacity() << endl; // 1
    // vectorVector.push_back(vector<string>({"second v"}));
    // cout << vectorVector.capacity() << endl; // 2 
    // vectorVector.push_back(vector<string>({"third v"}));
    // cout << vectorVector.capacity() << endl; // 4

    // cout << element.size() << endl; // gives a random number (why ?)
    // cout << vectorVector[0].size() << endl; // gives 1 (as expected)

    int h=0, l=4;
    for(int a=0; a<l; ++a)
    for(int b=a; b<l; ++b)
    for(int c=b; c<l; ++c)
    for(int d=c; d<l; ++d){
        cout << a << " " << b << " " << c << " " << d << endl;
        cout << h++ << endl;
    }

}