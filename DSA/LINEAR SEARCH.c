AIM:To write and understand an algorithm that searches for a given element (key) in a list/array using the Linear Search technique, where each                                             element is sequentially compared with the key until it is found or the end of the list is reached.
ALGORITHM:Step 1: Start
          Step 2: Input the array A and the number of elements n
          Step 3: Input the element to search, called key
          Step 4: Set i = 0
          Step 5: Repeat Steps 6–7 while i < n
          Step 6: If A[i] == key, then
                         Print "Element found at position i"
                  Go to Step 9
          Step 7: Increment i = i + 1
          Step 8: If i == n, print "Element not found"
          Step 9: Stop
PROGRAM:
#include <stdio.h>
int main()
{
    int i, size, elementTofind, found = 0;
    printf("enter the size of the array:");
    scanf("%d", &size);
    int arr[size];
    printf("enter %d elements:", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);// to enter elements into array
    }
    printf("enter the element to be searched:");
    scanf("%d", &elementTofind);
    for(int i = 0; i < size; i++)//loop to compare
    {
        if(arr[i] == elementTofind)//comparing each element to element to find
        {
            printf("element found at index :%d", i);
            found = 1;
            break;
        }
    }
    if(found == 0)//when element not found
    {
        printf("Invalid Input,please try again !!!");
    }
    return 0;
}
RESULT:
The Linear Search algorithm is successfully implemented.
The program correctly searches for the given element in the array and displays whether the element is found or not along with its position
