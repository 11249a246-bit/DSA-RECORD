#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Utility function to swap two integers
 * using pointers.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Partition function for QuickSort.
 * Places the pivot element in its correct sorted position
 * and arranges smaller elements to the left and larger to the right.
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Pivot chosen as last element
    int i = (low - 1);       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

/*
 * QuickSort with randomized pivot selection.
 * Randomization helps avoid worst-case performance.
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Randomly pick a pivot and move it to the end
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array around the chosen pivot
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Seed random generator for randomized pivot selection
    srand(time(NULL));

    printf("Enter number of elements: ");

    // Validate input size
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbersToSort[i]);
    }

    // Perform randomized QuickSort
    quickSort(numbersToSort, 0, n - 1);

    // Display sorted result
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbersToSort[i]);
    }

    return 0;
}
