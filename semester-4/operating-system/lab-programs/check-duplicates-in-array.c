/*
Algorithm: Check for Duplicate Elements in an Array

1. Start.
2. Read the number of elements in the array.
3. Input the array elements.
4. Assume no duplicates are present.
5. Compare each element with every other element after it.
6. If two elements are found to be equal:
   a) Mark duplicate as found.
   b) Stop further comparisons.
7. If a duplicate is found, display "Duplicates found".
8. Otherwise, display "No duplicates".
9. Stop.
   */

#include <stdio.h>

int main()
{
    int n, i, j, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                found = 1;
                break;
            }
        }
        if(found)
            break;
    }

    if(found)
        printf("Duplicates found");
    else
        printf("No duplicates");

    return 0;
}

/*
OUTPUT
Enter the number of elements: 5
Enter the elements:
5 8 2 5 9
Duplicates found
*/
