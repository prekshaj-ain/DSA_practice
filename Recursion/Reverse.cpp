#include<bits/stdc++.h>
using namespace std;
void reverse(string& S,int l,int h){
    if(l>h) return;
    swap(S[l],S[h]);
    reverse(S,l+1,h-1);
}
int main(){
    string S = "Preksha";
    reverse(S,0,6);
    cout << S;

    return 0;
}