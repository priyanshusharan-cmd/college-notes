/*
Algorithm: Find the Smallest Element in an Array

1. Start.
2. Read the number of elements in the array.
3. Input the array elements.
4. Assume the first element is the smallest.
5. Store its position.
6. Traverse the remaining elements of the array.
7. If a smaller element is found:
   a) Update the smallest element.
   b) Update its position.
8. After traversing the array, display the smallest element.
9. Display its position in the array.
10. Stop.
    */

#include <stdio.h>

int main()
{
    int n, i, min, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    min = arr[0];
    pos = 0;

    for(i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }

    printf("Smallest number: %d\n", min);
    printf("Position: %d\n", pos + 1);

    return 0;
}

/*
OUTPUT
Enter the number of elements: 5
Enter the elements:
4 6 8 9 10
Smallest number: 4
Position: 1
*/
