#include <bits/stdc++.h>
using namespace std;

int findMinIndex(int arr[], int j, int size)
{
    int minIndex = j;
    for (int i = j + 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int FirstIndex = i;
        int minIndex = findMinIndex(arr, i, size);
        if (FirstIndex != minIndex)
        {
            int temp = arr[FirstIndex];
            arr[FirstIndex] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int arr[] = {-3, -22, 0, 4, 1};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}