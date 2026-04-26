#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph

// Function to select the vertex with the smallest key value
// among the vertices not yet included in MST
int minKey(int key[], int visited[])
{
    int min = 999999;   // Initialize with a large value
    int min_index = 0;  // Store index of minimum value

    for (int i = 0; i < V; i++)
    {
        // Pick the smallest key among unvisited vertices
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the edges of the MST and total cost
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Start from vertex 1 since vertex 0 is the root
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores the MST structure
    int key[V];      // Minimum edge weight to include vertex in MST
    int visited[V];  // Tracks whether a vertex is included in MST

    // Step 1: Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    // Step 2: Start from the first vertex (vertex 0)
    key[0] = 0;      // Make key 0 so that this vertex is picked first
    parent[0] = -1;  // Root of MST

    // Step 3: Construct MST with V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the vertex with minimum key value
        int u = minKey(key, visited);

        visited[u] = 1; // Include selected vertex in MST

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update if:
            // 1. There is an edge (graph[u][v] != 0)
            // 2. Vertex v is not yet included in MST
            // 3. Weight of edge (u, v) is smaller than current key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Run Prim's Algorithm
    primMST(graph);

    return 0;
}
