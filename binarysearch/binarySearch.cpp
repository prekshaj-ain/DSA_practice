#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    while (end >= start)
    {
        // we should not do start + end as it might exceed the range of integer in c++
        int mid = start + (end - start) / 2;
        if (arr[mid] > target)
        {
            // then element must be in left side
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            // then element must be in right side
            start = mid + 1;
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
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = binarySearch(arr, 10, 5);
    cout << ans;
}