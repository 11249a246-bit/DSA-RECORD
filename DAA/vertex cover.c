#include <stdio.h>

#define V 5  // Number of vertices in the graph

/*
 * Greedy approximation algorithm for Vertex Cover.
 * This implements a simple 2-approximation strategy.
 */
void findVertexCover(int graph[V][V])
{
    int visited[V];  // Array to mark vertices included in the cover

    // Initially, no vertex is included in the cover
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Traverse all possible edges in the adjacency matrix
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            /*
             * If an edge exists between u and v, and both vertices
             * are not yet included in the cover, select both.
             */
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Include both endpoints in the vertex cover
                visited[u] = 1;
                visited[v] = 1;

                /*
                 * Once vertices are marked as included,
                 * all edges incident on them are effectively ignored
                 * in future iterations due to this condition check.
                 */
            }
        }
    }

    // Print the resulting vertex cover
    printf("Approximate Vertex Cover: ");

    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency matrix representation of the graph
    // 1 indicates an edge between vertices, 0 indicates no edge
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    findVertexCover(graph);

    return 0;
}
