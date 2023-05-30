#include<iostream>
using namespace std;

int IndexCount(int *arr , int *output, int size, int x){
    if(size == 0){
        return 0;
    }
    int short_ans = IndexCount(arr+1, output, size-1, x);

    for (int i=0;i<short_ans;i++){
        output[i] = output[i]+1;
    }
    if(arr[0]== x){
        for(int i=short_ans-1;i>=0;i--){
            output[i+1] = output[i]; 
        }
        output[0] = 0;
        return short_ans+1;
    }
    else{
        return short_ans;
    }
}

void IndexArray(int *arr, int size,int x){
    int output[size];
    int len = IndexCount(arr,output,size,x);
    for(int i=0;i<len;i++){
        cout << output[i]<< " ";
    }
}

int main(){
    int arr[] = {1,2,3,4,1,7};
    cout<< "Output: ";
    IndexArray(arr,7,1);
    return 0;
}