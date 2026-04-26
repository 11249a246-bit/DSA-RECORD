#include <stdio.h>

// Function to implement Best Fit Bin Packing
void bestFit(int items[], int n, int capacity) 
{ 
    printf("\nBest Fit Algorithm\n"); 
    
    int bin[n]; // Stores remaining capacity of each bin
    int binCount = 0; // Tracks number of bins used
    
    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity; 
    
    // Process each item
    for (int i = 0; i < n; i++) 
    { 
        int bestIndex = -1; // Index of best bin for current item
        int minSpace = capacity + 1; // Minimum leftover space after placement
        
        // Find the most suitable bin (least leftover space after placing item)
        for (int j = 0; j < binCount; j++) 
        { 
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            { 
                bestIndex = j; 
                minSpace = bin[j] - items[i]; 
            } 
        } 
        
        // If a suitable bin is found, place the item
        if (bestIndex != -1) 
        { 
            bin[bestIndex] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        } 
        else // If no suitable bin, create a new one
        { 
            bin[binCount] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], binCount + 1);
            binCount++; 
        } 
    } 
    
    // Display total bins used
    printf("Total bins used = %d\n", binCount); 
} 

int main()
{
    int n, capacity; 
    
    // Input number of items
    printf("Enter number of items: "); 
    scanf("%d", &n); 
    
    // Declare array to store item sizes (size depends on n)
    int items[n]; 
    
    // Input bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 
    
    printf("Enter item sizes:\n"); 
    
    // Read item sizes from user
    for (int i = 0; i < n; i++) 
    { 
        int itemSize; 
        printf("Item %d: ", i + 1); 
        scanf("%d", &itemSize); 
        
        // Validate item size before storing
        if (itemSize <= capacity) 
        { 
            items[i] = itemSize; 
        } 
        else 
        { 
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; // Retry input for same index
        } 
    } 
    
    // Call Best Fit algorithm
    bestFit(items, n, capacity); 
    
    return 0; 
}
