#include <bits/stdc++.h>
using namespace std;

int pivot(int arr[], int size)
{
    if (arr[0] < arr[size - 1])
    {
        return 0;
    }
    int start = 0;
    int end = size - 1;
    int mid;
    int first = arr[0];
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int prev = (mid + size - 1) % size;
        int next = (mid + 1) % size;
        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
        {
            return mid;
        }
        else if (arr[mid] > first)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    cout << pivot(arr, 6);
    return 0;
}