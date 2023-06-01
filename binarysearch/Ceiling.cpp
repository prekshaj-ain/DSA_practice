#include <bits/stdc++.h>
using namespace std;
int ceiling(int arr[], int size, int target)
{
    // if first element is smaller than target then return that
    if (arr[0] > target)
    {
        return 0;
    }
    //  target is bigger than last element, then ceil doesnot exist.
    if (arr[size - 1] < target)
    {
        return -1;
    }
    int res;
    int start = 0;
    int end = size - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > target)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 13, 18, 21, 22, 25, 27, 27, 28, 29};
    int ans = ceiling(arr, 10, 11);
    if (ans == -1)
    {
        cout << "Ceil does not exist";
    }
    else
    {
        cout << arr[ans];
    }
    return 0;
}