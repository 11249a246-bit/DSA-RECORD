#include <stdio.h>

// Structure to represent an item
struct Item
{
    int weight;   // Weight of the item
    int value;    // Value (profit) of the item
    float ppw;    // Profit per unit weight (value/weight ratio)
};

// Function to sort items in descending order of profit/weight ratio
void sort(struct Item items[], int n)
{
    struct Item temp;

    // Bubble sort based on ppw (higher ratio comes first)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Validate number of items
    if (n <= 0)
        return 1;

    struct Item items[n];

    // Input weight and value for each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value per unit weight
        items[i].ppw = (float)items[i].value / items[i].weight;
    }

    // Input capacity of the knapsack
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by decreasing profit/weight ratio
    sort(items, n);

    float totalProfit = 0.0;

    // Apply Fractional Knapsack strategy
    for (int i = 0; i < n; i++)
    {
        // If full item can be added
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Take fractional part of the item
            totalProfit += items[i].ppw * capacity;
            break; // Knapsack is full
        }
    }

    // Display the maximum profit obtained
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
