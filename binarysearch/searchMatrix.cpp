#include <bits/stdc++.h>
using namespace std;
pair<int, int> search(int arr[4][4], int n, int x)
{
    int smallest = arr[0][0];
    int largest = arr[n - 1][n - 1];
    if (x > largest || x < smallest)
    {
        return {-1, -1};
    }
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == x)
        {
            return {i, j};
        }
        else if (arr[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
}
int main()
{
    int arr[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    pair<int, int> ans = search(arr, 4, 31);
    cout << ans.first << ", " << ans.second;
    return 0;
}