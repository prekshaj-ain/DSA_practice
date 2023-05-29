#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int s,int e,int mid,int ele){
    if(s>e) return false;
    if(arr[mid]<ele) s = mid+1;
    else if(arr[mid]>ele) e = mid-1;
    else if(arr[mid] == ele) return true;
    return binarySearch(arr,s,e,e-(e-s)/2,ele);
}
int main(){
    int arr[] = {1,3,5,7,8,9};
    cout << binarySearch(arr,0,5,2,1);
    return 0;
}