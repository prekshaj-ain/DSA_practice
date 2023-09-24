#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool detectCycle(int V, vector<int> adj[])
{
    queue<pair<int, int> > q;
    int vis[V + 1] = {0};
    q.push({1, -1});
    vis[1] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int nbr : adj[node])
        {
            if (nbr != parent)
            {
                if (!vis[nbr])
                {

                    q.push({nbr, node});
                    vis[nbr] = 1;
                }
            }
        }
    }
}

int main()
{
}
