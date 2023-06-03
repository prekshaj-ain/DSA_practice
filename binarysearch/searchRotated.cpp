#include <bits/stdc++.h>
using namespace std;

int pivot(const vector<int> &arr, int size)
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

int binarySearch(const vector<int> &arr, int start, int end, int target)
{
    while (end >= start)
    {
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

int search(const vector<int> &arr, int B)
{
    if (arr[0] == B)
    {
        return 0;
    }
    int n = arr.size();
    if (arr[n - 1] == B)
    {
        return arr.size() - 1;
    }
    int pivotEle = pivot(arr, n);
    if (B > arr[0])
    {
        return binarySearch(arr, 0, pivotEle - 1, B);
    }
    else
    {
        return binarySearch(arr, pivotEle, n - 1, B);
    }
}
int main()
{
    const vector<int> arr = {194, 195, 196, 197, 198, 199, 201, 203, 204, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193};
    cout << search(arr, 9);
    return 0;
}