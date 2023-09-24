// based on divide and conquer
#include<iostream>
using namespace std;
void merge(int a[],int l,int mid,int r){
    int i = l;
    int j = mid+1;
    int k = l;
    int b[r];
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=r){
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for(int i1=l;i1<=r;i1++){
        a[i1] = b[i1];
    }


}
 void mergesort(int a[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);

    }
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    mergesort(arr,0,n);
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
