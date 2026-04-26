#include <stdio.h>

#define MAXN 15          // Maximum number of cities
#define INF 999999       // A large value representing infinity

int n;
int d[MAXN][MAXN];      // Cost matrix: d[i][j] = cost from city i to city j
int dp[MAXN][1 << MAXN]; // DP table: dp[i][S] stores minimum cost from city i visiting set S

// Function g(i, S)
// Returns the minimum cost to start from city i,
// visit all cities in set S, and return to starting city (city 0)
int g(int i, int S)
{
    // Base case: if no cities left to visit, return cost to go back to start
    if (S == 0)
        return d[i][0];

    // If already computed, return stored result
    if (dp[i][S] != -1)
        return dp[i][S];

    int minCost = INF;

    // Try visiting each city k present in set S
    for (int k = 0; k < n; k++)
    {
        // Check if city k is included in set S
        if (S & (1 << k))
        {
            // Calculate cost:
            // cost from i → k + cost of remaining tour starting from k
            int cost = d[i][k] + g(k, S & ~(1 << k));

            // Update minimum cost
            if (cost < minCost)
            {
                minCost = cost;
            }
        }
    }

    // Store result in DP table and return
    return dp[i][S] = minCost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1 (means "not computed yet")
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Initial call:
    // Start from city 0, visit all other cities (1 to n-1)
    int result = g(0, (1 << n) - 2);

    // Output minimum travelling cost
    printf("Minimum travelling cost = %d\n", result);

    return 0;
}
