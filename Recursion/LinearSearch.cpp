#include<bits/stdc++.h>
using namespace std;
bool dispatch(int arr[],int n,int ele){
    if(n==0) return false;
    if(arr[n-1] == ele) return true;
    return dispatch(arr,n-1,ele);
}
int main(){
    int arr[5] = {6,4,2,1,0};
    cout << dispatch(arr,5,0);
    return 0;
}