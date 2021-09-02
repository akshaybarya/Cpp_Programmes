#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &left, vector<int> &right, int n)
{
    int sum = 0;
    if (left.size() > right.size())
    {
        sort(left.begin(), left.end());
        for (int i = right.size(); i < left.size(); i++)
        {
            sum += left[i];
        }
    }
    else if (left.size() == right.size())
    {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        for (int i = 0; i < n; i++)
        {
            sum += abs(left[i] - right[i]);
        }
    }
    else
    {
        sort(right.begin(), right.end());
        for (int i = left.size(); i < right.size(); i++)
        {
            sum += right[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> left;
    vector<int> right;

    for (int i = 0; i < n; i++)
    {
        char t;
        int x;
        cin >> t >> x;

        if (t == 'L')
        {
            left.push_back(x);
        }
        else
        {
            right.push_back(x);
        }
    }
    cout << solve(left, right, n) << endl;
    return 0;
}