#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int, unordered_set<int> > &adj, int v1, int v2)
{
    adj[v1].insert(v2);
    adj[v2].insert(v1);
}

int main()
{
    unordered_map<int, unordered_set<int> > adj;
    int n, m;
    cout << "\n Enter number of vertices";
    cin >> n;
    cout << "\n Enter number of edges";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int vert1, vert2;
        cout << "\nEnter " << i + 1 << " edge";
        cin >> vert1 >> vert2;
        addEdge(adj, vert1, vert2);
    }

    return 0;
}
