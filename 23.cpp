#include <bits/stdc++.h>
using namespace std;

vector<int> arr, blocks;
int n = 0, blockSize = 0;

void updateQuery(int idx, int value)
{
    blocks[idx / blockSize] += value - arr[idx];
    arr[idx] = value;
}

int fetchSum(int l, int r)
{
    int sum = 0;

    //leftSum
    while (l % blockSize != 0 && l <= r)
    {
        sum += arr[l++];
    }
    //middle Sum
    while (l + blockSize <= r)
    {
        sum += blocks[l / blockSize];
        l += blockSize;
    }
    //right Sum
    while (l <= r)
    {
        sum += arr[l++];
    }
    return sum;
}

int main()
{
    cin >> n;
    blockSize = (int)ceil(sqrt(n));

    arr.resize(n, 0);
    blocks.resize(blockSize, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        blocks[i / blockSize] += x;
    }

    int queries;
    cin >> queries;

    while (queries--)
    {
        string s;
        cin >> s;

        if (s == "fetch")
        {
            int l, r;
            cin >> l >> r;
            cout << fetchSum(l, r) << "\n";
        }
        else
        {
            int idx, value;
            cin >> idx >> value;
            updateQuery(idx, value);
        }
    }
    return 0;
}