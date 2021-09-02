#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n)
{
    int res = 0;
    while (n != 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool no_div_by_3(vector<int> &a, int k, int n)
{
    int i = 0, no = 0, start = 0;
    while (i < k - 1)
    {
        no += sum_of_digits(a[i]);
        i++;
    }
    while (i < n)
    {
        no += sum_of_digits(a[i++]);

        if (no % 3 == 0)
        {
            return true;
        }

        no -= sum_of_digits(a[start++]);
    }
    return false;
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

    cout << no_div_by_3(a, k, n) << endl;
    return 0;
}