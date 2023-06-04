#include <bits/stdc++.h>

using namespace std;

int maxElement(vector<int> &nums)
{
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

int sumElements(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

int splitArray(vector<int> &nums, int k)
{
    int start = maxElement(nums);
    int end = sumElements(nums);
    if (k == nums.size())
    {
        return start;
    }
    else if (k == 1)
    {
        return end;
    }
    int mid;
    int ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        // cout << mid << endl;
        int partition = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                partition++;
                sum = nums[i];
            }
        }
        partition++;
        // cout << partition << endl;
        if (partition <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (partition > k)
        {

            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k);
    return 0;
}