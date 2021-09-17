#include <bits/stdc++.h>
using namespace std;

char change(char ch)
{
    if (ch == '>')
        return '<';
    return '>';
}

int maxTurbulenceSize(vector<int> a)
{
    int start = 0, count = 0, ans = -1;
    int i = 0, n = a.size();
    char ch = '>';
    while (i < n - 1)
    {
        if (count == 0)
        {
            if (a[i] > a[i + 1])
            {
                count = 1;
                ch = '>';
            }
            else
            {
                count = 1;
                ch = '<';
            }
        }
        if (ch == '>' and a[i] > a[i + 1])
        {
            count++;
        }
        else if (ch == '<' and a[i] < a[i + 1])
        {
            count++;
        }
        else
        {
            count++;
            ans = max(ans, count);
            count = 0;
        }
        ch = change(ch);
        i++;
    }
    count++;
    ans = max(ans, count);
    return ans;
}

int main()
{
    cout << maxTurbulenceSize({9, 4, 2, 10, 7, 8, 8, 1, 9}) << endl;
    return 0;
}