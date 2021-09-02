// number 3digit or 12 digit
// 123321

#include <bits/stdc++.h>
#define Speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
using namespace std;

bool isPalin(int n)
{
    int temp = n;
    int rev = 0;

    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (rev == n)
    {
        return true;
    }
    return false;
}

int brutForce(int n)
{
    int x = n + 1;
    while (x > 0)
    {
        if (isPalin(x))
        {
            return x;
        }
        x++;
    }
    return -1;
}

signed main()
{
    int n;
    cin >> n;
    // Time Complexity O(n^2)
    cout << brutForce(n) << endl;
    return 0;
}