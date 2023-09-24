#include <iostream>
using namespace std;
bool isSafe(int **a, int n, int x, int y)
{
    for (int row = 0; row < n; row++)
    {
        if (a[row][y] == 1)
        {
            return false;
        }
    }
    int row = x, column = y;
    while (row >= 0 && column >= 0)
    {
        if (a[row][column] == 1)
        {
            return false;
        }
        row--;
        column--;
    }
    row = x, column = y;
    while (row >= 0 && column < n)
    {
        if (a[row][column] == 1)
        {
            return false;
        }
        row--;
        column++;
    }
    return true;
}
bool nQueen(int **arr, int n, int x)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, n, x, col))
        {

            arr[x][col] = 1;

            if (nQueen(arr, n, x + 1))
            {
                return true;
            }
        arr[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if (nQueen(arr, n, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
