#include<iostream>
using namespace std;
void swap_alternate(int arr[],int size){
    int i = 0,j= 1;
    int temp;
    while(j<size){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i += 2;
        j = i+1;
    }
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }

}
int main(){
    int arr[9]={1,2,3,4,5,6,7,8,9},n=9;
    swap_alternate(arr,n);
    return 0;
}