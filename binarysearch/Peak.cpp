#include <bits/stdc++.h>
using namespace std;

int peak(int arr[], int size)
{
    if (arr[0] > arr[1])
    {
        return 0;
    }
    if (arr[size - 1] > arr[size - 2])
    {
        return size - 1;
    }
    int start = 0;
    int end = size - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        if (arr[mid] > arr[mid + 1])
        {
            // decresing part of array
            end = mid - 1;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            // increasing part
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 7, 10, 15, 35};
    cout << peak(arr, 5);
    return 0;
}