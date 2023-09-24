#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
     // swap
    int temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;
    return j;
}
void quickSort(int arr[], int start,int end)
{
    if(start<end){
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);


    }

}
int main(){
    int n;
    cin >>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    return 0;
}