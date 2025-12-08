#include <iostream>
using namespace std;

void BFS(int adj[10][10], int n, int start)
{
    int visited[10] = {0};
    int q[100], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear)
    {
        int node = q[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
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

    BFS(adj, n, 0);

    return 0;
}