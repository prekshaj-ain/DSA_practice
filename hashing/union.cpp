#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    int a[5] = {1,2,3,4,1};
    int b[3] = {6,1,2};
    for(auto i:a){
        s.insert(i);
    }
    for(auto i:b){
        s.insert(i);
    }
    cout << s.size();
    return 0;
}