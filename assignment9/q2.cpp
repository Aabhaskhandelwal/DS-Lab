#include <iostream>
using namespace std;

void DFSUtil(int adj[10][10], int n, int node, int visited[])
{
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
            DFSUtil(adj, n, i, visited);
    }
}

void DFS(int adj[10][10], int n, int start)
{
    int visited[10] = {0};
    cout << "DFS Traversal: ";
    DFSUtil(adj, n, start, visited);
    cout << endl;
}

int main()
{
    int n = 5;

    int adj[10][10] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    DFS(adj, n, 0);

    return 0;
}
