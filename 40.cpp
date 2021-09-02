#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> a(n, vector<string>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> w, l;

    for (int i = 0; i < n; i++)
    {
        if (a[i][1] == "W")
        {
            w.push_back(stio(a[i][2]));
        }
        else
        {
            l.push_back(stio(a[i][2]));
        }
    }

    int i = 0, j = 0, diff = 0, b1 = -1, b2 = -1;

    /*
    10 50        
    10 20 5
*/

    while (i < w.size() and j < l.size())
    {
        if (diff < 0)
        {
            diff += w[i++];
        }
        if (diff > 0)
        {
            diff -= l[j++];
        }
        else
            diff = w[i++] - l[j++];
    }

    if (i >= w.size())
    {
        while (j < l.size() and diff > 0)
        {
            diff -= l[j++];
            b2 = j;
        }
    }
    else if (j >= l.size())
    {
        while (i < w.size() and diff < 0)
        {
            diff += w[i++];
            b1 = i;
        }
    }

    cout << "Full matched :"
         << " ";
    if (b1 < w.size())
    {
        for (auto it : w)
        {
            cout << it << " ";
        }

        for (int x = 0; x < b2; x++)
        {
            cout << l[x] << " ";
        }
    }
    else if (b2 < l.size())
    {
        for (auto it : l)
        {
            cout << it << " ";
        }

        for (int x = 0; x < b1; x++)
        {
            cout << w[x] << " ";
        }
    }

    int q = b1 == -1 ? l[b2] : w[b1];
    cout << "\nPartially Matched :"
         << " " << q;

    cout << "\nNot Matched :"
         << " ";
    if (b1 < w.size())
    {
        for (int x = b2 + 1; x < b2; x++)
        {
            cout << l[x] << " ";
        }
    }
    else if (b2 < l.size())
    {
        for (int x = b1 + 1; x < b1; x++)
        {
            cout << w[x] << " ";
        }
    }
    return 0;
}