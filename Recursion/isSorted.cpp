#include<bits/stdc++.h>
using namespace std;
bool dispatch(int arr[],int n){
    if(n<=1) return true;
    if(arr[n-2]>arr[n-1]) return false;
    return dispatch(arr,n-1);
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout << dispatch(arr,5);
    return 0;
}