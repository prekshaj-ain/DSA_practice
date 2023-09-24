#include <iostream>
using namespace std;
int search(int a[], int n, int key)
{
    int start = 0;
    int end = n;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (a[mid] < key)
        {
            start = mid+1;
            mid = (start + end) / 2;
        }
        else if (a[mid] > key)
        {
            end = mid-1;
            mid = (start + end) / 2;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n], key;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter the value you want to search";
    cin >> key;
    cout << search(arr,n,key);
}