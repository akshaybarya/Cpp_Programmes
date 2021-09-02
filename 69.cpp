#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

signed main()
{
    string s;
    cin >> s;
    int n = s.length();

    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    int ans = 0;
    unordered_map<char, int>::iterator it = mp.begin();
    while (it != mp.end())
    {
        if (it->second == 1)
        {
            ans++;
        }
        it++;
    }
    cout << ans << endl;
    return 0;
}