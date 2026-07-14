/*
Algorithm: Linear Search and Binary Search

1. Start.
2. Read the number of elements in the array.
3. Input the array elements.
4. Read the key element to be searched.
5. Display the search options:
   a) Linear Search
   b) Binary Search
6. Read the user's choice.
7. If Linear Search is selected:
   a) Compare the key with each element sequentially.
   b) If found, return its index.
   c) Otherwise, return -1.
8. If Binary Search is selected:
   a) Initialize left and right pointers.
   b) Find the middle element.
   c) If key equals middle element, return its index.
   d) If key is greater, search the right half.
   e) If key is smaller, search the left half.
   f) Repeat until the element is found or the search space becomes empty.
9. If the returned index is -1, display "Element not found".
10. Otherwise, display the index of the element.
11. Stop.
    */

#include <stdio.h>

int linear(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int binary(int a[], int n, int key)
{
    int l = 0, r = n - 1;

    while(l <= r)
    {
        int m = l + (r - l) / 2;

        if(a[m] == key)
            return m;
        else if(a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    int n, key, choice, res;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("1. Linear Search\n2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        res = linear(a, n, key);
    else if(choice == 2)
        res = binary(a, n, key);
    else
    {
        printf("Invalid choice\n");
        return 0;
    }

    if(res == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", res);

    return 0;
}

/*
OUTPUT
Enter number of elements: 4
Enter elements:
2 4 6 9
Enter key to search: 6
Enter choice: 1
Element found at index 2
*/
