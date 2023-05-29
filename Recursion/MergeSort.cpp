#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int i = l;
    int j = mid+1;
    int k = 0;
    int n = r - l +1;
    int b[n] = {0};
    while(i<=mid && j<=r){
        if(arr[i] > arr[j])
            b[k++] = arr[j++];
        else
            b[k++] = arr[i++];
    }
    while(i<=mid) b[k++] = arr[i++];
    while(j<=r) b[k++] = arr[j++];
    k=0;
    for(int m=l;m<=r;m++){
        arr[m] = b[k++];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r) return;
    int mid = r - (r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    int arr[10] = {6,5,4,3,2,8,7,1,9};
    mergeSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}