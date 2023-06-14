#include <bits/stdc++.h>
using namespace std;

void combinations(int k, int n, int start, vector<int> &combination)
{
    if (k == 0)
    {
        cout << "[";
        for (int ele : combination)
        {
            cout << ele << ",";
        }
        cout << "]";
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        combination.push_back(i);
        combinations(k - 1, n, i + 1, combination);
        combination.pop_back();
    }
}

int main()
{
    vector<int> comb;
    combinations(2, 4, 1, comb);
    return 0;
}