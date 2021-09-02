#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    vector<int> jumps(n + 1, INT_MAX);
    jumps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= j + a[j])
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    cout << jumps[n - 1] << endl;
    return 0;
}