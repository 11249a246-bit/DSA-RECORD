#include <stdio.h>

void firstFit(int items[], int n, int capacity)
{
    int bin[n];
    int binCount = 0;   // Stores the number of bins currently used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int placed = 0;   // Checks whether the item has been placed

        // Check the existing bins
        for (int j = 0; j < binCount; j++)
        {
            // Place item in the current bin if it fits
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];   // Reduce remaining space in the bin
                printf("Item %d with weight %d placed in bin %d", i + 1, items[i], j + 1);
                placed = 1;
                break;   // Stop after the first suitable bin is found
            }
        }

        // Create a new bin if the item does not fit in any existing bin
        if (!placed)
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d with weight %d placed in bin %d", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d", binCount);
}

int main()
{
    int n, capacity;
    int items[100];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);

        if (items[i] > capacity)
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.");
            i--;
        }
    }

    firstFit(items, n, capacity);

    return 0;
}
