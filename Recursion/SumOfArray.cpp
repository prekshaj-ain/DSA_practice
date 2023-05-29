#include<bits/stdc++.h>
using namespace std;
int dispatch(int arr[],int n){
    if(n==1) return n;
    int ans = arr[n] + arr[n-1];
    return dispatch(arr,n-2) + ans;
}
int main(){
    int arr[5]={1,2,4,5,7};
    cout << dispatch(arr,5);
    return 0;
}