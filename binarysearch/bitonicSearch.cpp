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

int binarySearch(int arr[], int size, int target, bool asc)
{
    int start = 0;
    int end = size - 1;
    while (end >= start)
    {
        // we should not do start + end as it might exceed the range of integer in c++
        int mid = start + (end - start) / 2;
        if (arr[mid] > target)
        {
            // if array is in ascending order then element must be in left else element is in right
            asc ? end = mid - 1 : start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            asc ? start = mid + 1 : end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    // not found
    return -1;
}

int searchBitonic(int arr[], int size, int target)
{
    int peakElement = peak(arr, size);
    int result1 = binarySearch(arr + peakElement, size - peakElement, target, false);
    if (result1 == -1)
    {
        return binarySearch(arr, size, target, true);
    }
    return result1 + peakElement;
}

int main()
{
    int arr[] = {1, 7, 10, 15, 35, 30, 25, 5};
    cout << searchBitonic(arr, 8, 25);
    return 0;
}