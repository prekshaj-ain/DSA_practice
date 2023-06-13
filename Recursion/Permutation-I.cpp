#include <bits/stdc++.h>
using namespace std;

void helper(string str, int pos, vector<string> &ans)
{
    if (pos == str.length() - 1)
    {
        ans.push_back(str);
        return;
    }

    for (int i = pos; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
        {
            continue;
        }
        swap(str[i], str[pos]);
        helper(str, pos + 1, ans);
        swap(str[i], str[pos]);
    }
}

vector<string> permutation(string str)
{
    vector<string> ans;
    sort(str.begin(), str.end());
    helper(str, 0, ans);
    return ans;
}
int main()
{
    string str = "aba";
    vector<string> ans = permutation(str);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}