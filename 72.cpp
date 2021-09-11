#include <bits/stdc++.h>
using namespace std;

struct result
{
    result() : output1(){};
    int output1[100];
};

struct result toffes(int input1, int input2)
{
    int n = input1, k = input2;

    int ans[k];
    memset(ans, 0, sizeof(ans));
    int i = 0, x = 0, prev = 0;
    while (x <= n)
    {
        i = i % k;
        prev++;
        if (x + prev >= n)
        {
            ans[i] += n - x;
            break;
        }
        x = x + prev;
        ans[i] += prev;
        i++;
    }

    result *rs = new result();

    for (int i = 0; i < k; i++)
    {
        rs.output1[i] = ans[i];
    }
    return rs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*int m, n;
    cin >> m >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxUniqueSum(m, n, a);*/
    result *rs = toffes(10, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << rs.output1[i] << " ";
    }
    return 0;
}