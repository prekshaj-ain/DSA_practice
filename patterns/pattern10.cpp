#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int row = 1; row <= n; row++)
    {
        int col;
        for (col = 0; col < n - row; col++)
        {
            cout << " ";
        }
        for (; col < n; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}