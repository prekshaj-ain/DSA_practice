#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int target, bool first)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
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
            ans = mid;
            first ? end = mid - 1 : start = mid + 1;
        }
    }
    return ans;
}
void indexes(int arr[], int size, int target)
{
    int ans[2];
    ans[0] = binarySearch(arr, size, target, true);
    ans[1] = binarySearch(arr, size, target, false);
    cout << ans[0] << " " << ans[1];
}
int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int size = 9;
    indexes(arr, size, 1);
    return 0;
}