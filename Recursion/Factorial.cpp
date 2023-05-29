#include<bits/stdc++.h>
using namespace std;
int dispatcher(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int ans = dispatcher(n-1) + dispatcher(n-2);
    return ans;
}
int main(){
    int n; 
    cout << "Enter the term you want to get";
    cin>>n;
    cout<<dispatcher(n);
    return 0;
}