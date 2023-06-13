#include <bits/stdc++.h>
using namespace std;
int findPivot(int arr[], int s, int e)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] < arr[0] && arr[mid] < arr[mid - 1])
        return mid;
    else if (arr[mid] > arr[0])
        return findPivot(arr, mid + 1, e);
    else
        return findPivot(arr, s, mid - 1);
}
int main()
{
    int arr[] = {3, 4, 8, 10, 11, 12};
    cout << findPivot(arr, 0, 6);
    return 0;
}