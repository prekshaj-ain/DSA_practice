#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    if (end < start)
    {
        return -1;
    }
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
            return mid;
        }
    }
    // not found
    return -1;
}

int findPos(int arr[], int target)
{
    int start = 0;
    int end = 1;
    while (arr[end] < target)
    {
        int temp = end + 1;
        end = 2 * (end - start + 1) + end;
        start = temp;
    }
    return binarySearch(arr, start, end, target);
}

int main()
{
    int a[] = {2, 3, 4, 5, 7, 8, 9, 11, 22, 35, 48, 51, 82, 95, 115, 270};
    int target = 12;
    int result = findPos(a, target);
    cout << result;
    return 0;
}