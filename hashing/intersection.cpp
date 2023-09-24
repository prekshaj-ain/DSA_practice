#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    int a[5]={1,2,3,4,5};
    int b[3] = {1,5,6};
    for(int i:a){
        s.insert(i);
    }
    int c=0;
    for(int i:b){
        if(s.count(i)){
            c++;
            s.erase(i);
        }
    }
    cout << c;
}