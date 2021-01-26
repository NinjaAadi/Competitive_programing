#include <bits/stdc++.h>

#include <iterator>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<int> res(10);
    res.push_back(1);
    res.push_back(2);
    res.push_back(12);
    res.push_back(4);
    res.push_back(15);
    res.push_back(6);
    //vector<string>::iterator i; //Vectors
    //vector<int>::iterator it; //Vectors
    auto j = res.begin();
    for (auto i = res.begin(); i != res.end(); i++) {
        cout << (*i) << " ";
    }
    cout << endl;

    // for(auto i : res){
    //     cout<<i<<" ";
    // }
}