#include <bits/stdc++.h>
using namespace std;

void cyclicSort(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        int correctIndex = arr[i] - 1;
        if (i != correctIndex)
        {
            int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    cyclicSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}