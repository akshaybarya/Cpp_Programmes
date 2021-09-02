#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
int solve(vector<int> &a, int n, int v)
{
    int ans = 0;
    while (ans >= 0)
    {
        sort(a.begin(), a.end());
        if (a[0] == 0 and a[n - 1] == 0)
            break;
        int x = lower_bound(a.begin(), a.end(), v) - a.begin();
        if (x == n)
            x = x - 1;
        if (a[x] > v)
        {
            a[x] = 2 * (a[x] - v);
        }
        else
        {
            a[x] = 0;
        }
        v = 2 * v;
        ans++;
    }
    return ans;
}
*/
int solve2(vector<int> &input3, int input1, int input2)
{
    sort(input3.begin(), input3.end());
    int i = 0, days = 0;

    while (i < input1)
    {
        if (input3[i] == 0)
        {
            i++;
            continue;
        }
        if (input3[i] > input2)
        {
            int w = 2 * (input3[i] - input2);
            input3[i] = w > input3[i] ? input3[i] : w;
        }
        else
        {
            input3[i] = 0;
            i++;
        }
        input2 *= 2;
        days++;
    }
    return days;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    int v;
    cin >> v;

    cout << solve2(a, n, v) << endl;
    return 0;
}