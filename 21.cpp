#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int Laddar;
    cin >> Laddar;
    map<int, int> ladder;
    for (int i = 0; i < Laddar; i++)
    {
        int u, v;
        cin >> u >> v;

        ladder[u] = v;
    }
    int Snake;
    cin >> Snake;
    map<int, int> snake;
    for (int i = 0; i < Snake; i++)
    {
        int u, v;
        cin >> u >> v;

        snake[u] = v;
    }

    vector<bool> visited(101, false);
    queue<int> q;
    q.push(1);
    bool found = false;
    visited[1] = true;
    int moves = 0;
    while (!q.empty() and !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                {
                    found = true;
                }
                if (t + die <= 100 and ladder[t + die] and !visited[ladder[t + die]])
                {
                    visited[ladder[t + die]] = true;
                    if (ladder[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(ladder[t + die]);
                }
                else if (t + die <= 100 and snake[t + die] and !visited[snake[t + die]])
                {
                    visited[snake[t + die]] = true;
                    if (snake[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(snake[t + die]);
                }
                else if (t + die <= 100 and !visited[t + die] and !snake[t + die] and !ladder[t + die])
                {
                    visited[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }

    cout << moves << endl;
    return 0;
}