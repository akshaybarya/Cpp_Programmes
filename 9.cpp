#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0 && i * i == n)
        {
            sum += i;
        }
        else if (n % i == 0)
        {
            sum += i + n / i;
        }
    }
    if (sum == n)
        return true;
    return false;
}

int perfect_numbers(vector<int> &a, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isPerfect(a[i]))
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    int cnt = 0, start = 0, mx = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == 1)
            cnt++;
    }
    mx = cnt;
    for (int i = k; i < n; i++)
    {
        if (a[start] == 1)
        {
            cnt--;
        }
        start++;
        if (a[i] == 1)
            cnt++;
        mx = max(mx, cnt);
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    int k;
    cin >> k;

    cout << perfect_numbers(a, n, k) << endl;
    return 0;
}