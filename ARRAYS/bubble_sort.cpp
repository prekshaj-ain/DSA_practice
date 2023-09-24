// compare a pair of elements in the array and sort them.array will start sorting backwards
#include<iostream> 
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    //bubble sort
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    
}