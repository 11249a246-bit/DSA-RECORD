#include <stdio.h>

#define V 5        // Number of vertices
#define INF 999999 // A large value representing infinity

// Function to select the unvisited vertex with the smallest distance
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        // Choose the vertex with minimum distance that is not yet visited
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's shortest path algorithm
void dijkstra(int graph[V][V])
{
    int dist[V];     // Stores shortest distance from source
    int visited[V];  // Tracks whether a vertex is processed

    // Step 1: Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;   // Set all distances to infinity
        visited[i] = 0;  // Mark all vertices as unvisited
    }

    // Step 2: Set source vertex (0) distance to 0
    dist[0] = 0;

    // Step 3: Process all vertices
    for (int count = 0; count < V; count++)
    {
        // Pick the unvisited vertex with smallest distance
        int u = extractMin(dist, visited);

        // If no vertex is reachable, stop
        if (u == -1)
            break;

        visited[u] = 1; // Mark vertex as visited

        // Step 4: Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            // Check if:
            // 1. There is an edge from u to j
            // 2. Vertex j is not visited
            if (graph[u][j] > 0 && !visited[j])
            {
                // Relaxation: update distance if shorter path is found
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Step 5: Print shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d --> %d\n", i, dist[i]);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Run Dijkstra's Algorithm
    dijkstra(graph);

    return 0;
}
