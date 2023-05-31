// hello -> hel*lo
#include<bits/stdc++.h>
using namespace std;

string pairStar(string str){
    if(str.length() < 2){
        return str;
    }
    string smallans = pairStar(str.substr(1));
    if(str[0] == smallans[0]){
        smallans = '*'+smallans;
    }
    return str[0]+smallans;
}

int main(){
    string str = "aaaa";
    string output = pairStar(str);
    cout << output;
    return 0;
}