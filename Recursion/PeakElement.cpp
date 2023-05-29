#include<bits/stdc++.h>
using namespace std;
int PeakElement(int arr[],int s,int e,int n){
    if(s>e) return -1;
    int mid = e - (e - s)/2;
    if((arr[mid] > arr[mid - 1] && arr[mid] > arr[mid +1]) || 
        (mid == n-1 && arr[mid] > arr[mid -1]) ||
        (mid == 0 && arr[mid] > arr[mid+1]))
        return mid;
    else if(arr[mid] > arr[mid-1]){
        return PeakElement(arr,mid+1,e,n);
    }
    else return PeakElement(arr,s,mid-1,n);

}
int main(){
    int arr[8] = {1, 2, 3, 4, 4, 3, 2,1};
    cout <<PeakElement(arr,0,7,8);
    return 0;
}