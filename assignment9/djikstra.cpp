#include <iostream>
using namespace std;

void Dijkstra(int adj[10][10], int n, int start)
{
    int dist[10], visited[10];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1, minDist = 9999;

        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra Shortest Distances from " << start << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << "\n";
}

int main()
{
    int n = 5;

    int adj[10][10] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    Dijkstra(adj, n, 0);

    return 0;
}