#include <iostream>
using namespace std;

// ======================= KRUSKAL =========================

int parent[20];

int findSet(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    parent[b] = a;
}

void bubbleSortEdges(int edges[][3], int e)
{
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (edges[j][2] > edges[j + 1][2])
            {
                int t1 = edges[j][0], t2 = edges[j][1], t3 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = t1;
                edges[j + 1][1] = t2;
                edges[j + 1][2] = t3;
            }
}

void Kruskal(int edges[][3], int e, int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = i;

    bubbleSortEdges(edges, e);

    int mst = 0;
    cout << "Kruskal MST:\n";

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (findSet(u) != findSet(v))
        {
            unionSet(u, v);
            cout << u << " - " << v << " (" << w << ")\n";
            mst += w;
        }
    }

    cout << "Total Weight = " << mst << "\n";
}

// ======================= PRIM =========================

void Prim(int adj[10][10], int n)
{
    int key[10], visited[10], parent[10];
    for (int i = 0; i < n; i++)
    {
        key[i] = 9999;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int minKey = 9999, u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && key[i] < minKey)
            {
                minKey = key[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    cout << "\nPrim MST:\n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << " (" << adj[parent[i]][i] << ")\n";
        total += adj[parent[i]][i];
    }
    cout << "Total Weight = " << total << "\n";
}

// ======================= MAIN =========================

int main()
{
    int n = 5;

    int edges[20][3] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 5}};

    int adj[10][10] = {
        {0, 2, 3, 0, 0},
        {2, 0, 1, 4, 0},
        {3, 1, 0, 5, 0},
        {0, 4, 5, 0, 0},
        {0, 0, 0, 0, 0}};

    Kruskal(edges, 5, n);
    Prim(adj, n);

    return 0;
}