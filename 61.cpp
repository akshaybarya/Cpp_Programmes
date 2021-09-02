// 2 sorted arrays
// return merge array

#include <bits/stdc++.h>
using namespace std;

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void merge(vector<int> &a1, vector<int> &a2, int n1, int n2)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n1 and j < n2)
    {
        if (a1[i] < a2[j])
        {
            ans.push_back(a1[i]);
            i++;
        }
        else
        {
            ans.push_back(a2[j]);
            j++;
        }
    }

    while (i < n1)
    {
        ans.push_back(a1[i++]);
    }

    while (j < n2)
    {
        ans.push_back(a2[j++]);
    }

    // printing the resultant array
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    //size of arrays
    int n1 = 5, n2 = 5;
    vector<int> a1 = {1, 5, 9, 11, 13};
    vector<int> a2 = {3, 6, 7, 10, 12};

    merge(a1, a2, n1, n2);
    return 0;
}