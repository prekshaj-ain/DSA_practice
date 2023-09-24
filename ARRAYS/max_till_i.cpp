#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n],mx[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    mx[0] = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]> mx[i-1]) mx[i] = arr[i];
        else mx[i] = mx[i-1];
    }
    for(int i=0 ; i<n ; i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    for(int i=0 ; i<n ; i++){
        cout << mx[i]<< " ";
    }
}