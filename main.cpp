#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;
};

void bellmanFord(Edge arr[], int n, int v, int src)
{
    int dist[v];
    int parent[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = INT_MAX;
    }
    dist[src] = 0;
    parent[src] = -1;
    for (int i = 0; i < v - 1; i++)
    {
        for (int k = 0; k < n; k++)
        {

            if ((dist[arr[k].src] != INT_MAX) && (dist[arr[k].src] + arr[k].weight < dist[arr[k].dest]))
            {
                dist[arr[k].dest] = dist[arr[k].src] + arr[k].weight;
                parent[arr[k].dest] = arr[k].src;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        if ((dist[arr[k].src] != INT_MAX) && (dist[arr[k].src] + arr[k].weight < dist[arr[k].dest]))
        {
            cout << "graph contains negative cycle" << endl;
            return;
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << "path of " << src << " to " << i << "is : ";
        string path = "" + to_string(i);
        int temp = i;
        while (parent[temp] != -1)
        {
            path += to_string(parent[temp]);
            temp = parent[temp];
        }
        for (int j = path.size() - 1; j >= 0; j--)
        {
            cout << "-->" << path[j];
        }
        cout << " and weight is: " << dist[i] << endl;
    }
}

int main()
{

    Edge arr[] = {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}, {1, 3, 6}, {2, 3, 1}};
    int n = 5;
    int v = 4;
    int src = 0;
    bellmanFord(arr, n, v, src);

    return 0;
}
