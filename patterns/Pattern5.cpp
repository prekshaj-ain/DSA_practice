#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int row = 1; row < (2 * n); row++)
    {
        int c;
        if (row > n)
        {
            c = n - (row % n);
        }
        else
        {
            c = row;
        }

        for (int col = 0; col < c; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}