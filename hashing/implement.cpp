#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout<<endl<<s.size();
    if(s.find(5) == s.end()){
        cout << "not found";
    }
    else{
        cout << "found";
    }
    for(auto it = s.begin();it != s.end();it++)
    {
        cout << *it<<" ";
    }
    // s.clear();
    // cout <<s.size();
    cout << s.count(1)<<" "; //count only return 1 or 0. 1 is present 0 if absent.
    // s.erase(1);
    // cout<<s.size();
    // s.erase(s.begin(),s.end());
    return 0;
}