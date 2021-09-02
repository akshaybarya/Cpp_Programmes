#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(vector<int> &a, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (a[i] != a[end - i])
        {
            return false;
        }
    }
    return true;
}

int Palindrome(vector<int> &a, int k, int n)
{
    int i = 0, start = 0, ans = -1;
    while (i < k)
    {
        i++;
    }
    while (i < n)
    {
        if (isPalindrome(a, start, i))
        {
            ans = start;
            break;
        }
        start++;
        i++;
    }
    return ans;
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

    int res = Palindrome(a, k, n);
    if (res == -1)
    {
        cout << "Not feasible" << endl;
        return 0;
    }
    for (int i = res; i < res + k; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}