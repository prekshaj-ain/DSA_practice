#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int> candidates, int target, int start, vector<int> combination)
{
    int n = candidates.size();
    if (target == 0)
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
    for (int i = start; i < n; i++)
    {
        if (candidates[i] > target)
        {
            break;
        }
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i, combination);
        combination.pop_back();
    }
}

int main()
{
    combinationSum({2, 3, 6, 7}, 7, 0, {});
    return 0;
}