#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target)
{
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    bool b = true;
    while (i < j)
    {
        int x = i + 1, y = j - 1;
        while (x < y)
        {
            if (nums[i] + nums[j] + nums[x] + nums[y] == target)
            {
                ans.insert({nums[i], nums[j], nums[x], nums[y]});
                x++;
                y--;
            }
            else if (nums[i] + nums[j] + nums[x] + nums[y] < target)
            {
                x++;
            }
            else
            {
                y--;
            }
        }
        if (b)
        {
            i++;
            b = false;
        }
        else
        {
            j--;
            b = true;
        }
    }
    vector<vector<int>> v(ans.begin(), ans.end());
    return v;
}

int main()
{
    vector<vector<int>> a = fourSum({-3, -1, 0, 2, 4, 5}, 0);

    for (auto it : a)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}