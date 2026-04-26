#include <stdio.h>

#define V 5   // Number of vertices
#define E 6   // Number of edges

int parent[V]; // Array for Union-Find structure

// Function to find the representative (root) of a set
int findLeader(int v)
{
    // Traverse until reaching the root of the set
    while (parent[v] != v)
        v = parent[v];

    return v;
}

// Function to merge two sets (Union operation)
void mergeSets(int u, int v)
{
    int a = findLeader(u);
    int b = findLeader(v);

    // Attach one set to another
    parent[a] = b;
}

// Function to sort edges in ascending order of weight
void sortEdges(int edges[E][3])
{
    // Bubble sort based on edge weight (edges[][2])
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                // Swap entire edge (u, v, weight)
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

// Function to implement Kruskal's Algorithm
void kruskal(int edges[E][3])
{
    // Step 1: Sort edges by increasing weight
    sortEdges(edges);

    // Step 2: Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0; // Number of edges selected in MST
    int cost = 0;  // Total cost of MST

    printf("Selected Edges:\n");

    // Step 3: Process edges one by one
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // Check if including this edge forms a cycle
        if (findLeader(u) != findLeader(v))
        {
            // Include edge in MST
            printf("%d -- %d (Weight: %d)\n", u, v, w);

            mergeSets(u, v); // Union the sets
            cost += w;
            count++;
        }

        // Stop when MST has (V - 1) edges
        if (count == V - 1)
            break;
    }

    // Print total cost of MST
    printf("Total Cost: %d\n", cost);
}

int main()
{
    // Edge list: {source, destination, weight}
    int edges[E][3] = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5},
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    };

    // Run Kruskal's Algorithm
    kruskal(edges);

    return 0;
}
