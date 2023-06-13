#include <bits/stdc++.h>
using namespace std;

vector<string> permutation(string str)
{
    vector<string> ans;
    int n = str.length();
    if (str.empty())
    {
        ans.push_back("");
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == str[i + 1])
        {
            continue;
        }
        string remainingStr = str.substr(0, i) + str.substr(i + 1);
        vector<string> shortAns = permutation(remainingStr);
        for (auto ele : shortAns)
        {
            string perm = str[i] + ele;
            ans.push_back(perm);
        }
    }
    return ans;
}

int main()
{
    string str = "aac";
    sort(str.begin(), str.end());
    vector<string> ans = permutation(str);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}