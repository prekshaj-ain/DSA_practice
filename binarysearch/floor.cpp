#include <bits/stdc++.h>
using namespace std;

int floor(int arr[], int size, int target)
{
    if (arr[0] > target)
    {
        return -1;
    }
    if (arr[size - 1] < target)
    {
        return size - 1;
    }
    int ans;
    int start = 0;
    int end = size - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10, 13, 18, 21, 22, 25, 27, 27, 28, 29};
    int ans = floor(arr, 10, 21);
    if (ans == -1)
    {
        cout << "floor does not exist";
    }
    else
    {
        cout << arr[ans];
    }
    return 0;
}