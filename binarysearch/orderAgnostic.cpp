#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    bool asc;
    (arr[0] > arr[size - 1]) ? asc = false : asc = true;
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
            return mid + 1;
        }
    }
    // not found
    return -1;
}

int main()
{
    int arr[] = {60, 55, 40, 32, 9, 2};
    cout << binarySearch(arr, 6, 40);
    return 0;
}