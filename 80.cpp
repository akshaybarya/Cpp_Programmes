#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> a)
{
    vector<int> ans;

    int rowend = a.size(), colend = a[0].size();
    int rowstart = 0, colstart = 0;

    while (colstart < colend and rowstart < rowend)
    {
        cout << "row " << rowstart << " " << rowend << endl;
        cout << "col " << colstart << " " << colend << endl;
        for (int i = colstart; i < colend; i++)
        {
            ans.push_back(a[rowstart][i]);
        }
        rowstart++;
        for (int i = rowstart; i < rowend; i++)
        {
            ans.push_back(a[i][colend - 1]);
        }
        colend--;
        for (int i = colend - 1; i >= colstart; i--)
        {
            ans.push_back(a[rowend - 1][i]);
        }
        rowend--;
        for (int i = rowend - 1; i >= rowstart; i--)
        {
            ans.push_back(a[i][colstart]);
        }
        colstart++;
    }
    return ans;
}

int main()
{
    /*
        1 2  3  4
        5 6  7  8
        9 10 11 12
    */
    vector<int> ans = spiralOrder({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}