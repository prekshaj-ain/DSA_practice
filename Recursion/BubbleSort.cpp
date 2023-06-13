#include <iostream>
using namespace std;
void bubbleSort(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }
    bool swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swapped = true;
        }
    }
    if (!swapped)
        return;
    bubbleSort(arr, size - 1);
}
int main()
{
    int arr[] = {4, 3, 1, 9, 1};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
