#include<iostream>
using namespace std;

int search( int a[],int n, int key){
    for(int i = 0;i<n;i++){
        if(a[i] == key) return i;

    }
    return -1;
}
int main(){
    int n,key;
    cin >> n;
    int arr[n];
    // creating array
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    cout << "\n Enter the number you want to search";
    cin >> key;
    cout << search(arr,n,key);
    
    return 0;
}
