/*
-------------------------------------------------------
Program    : Question 5
Subject    : Design and Analysis of Algorithms
Language   : C
Author     : Pratyush Kumar Mallick
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
#include <stdio.h>

int findPartitionPoint(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if mid is the first occurrence of 1
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0))
            return mid;

        if (arr[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // No partition point found
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements (only 0s followed by 1s):\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int partition = findPartitionPoint(arr, n);

    if (partition == -1)
        printf("Partition point not found.\n");
    else
    {
        printf("Partition Point Index = %d\n", partition);
        printf("First 1 is at index %d\n", partition);
    }

    return 0;
}