/*
-------------------------------------------------------
Program    : Question 6 
Subject    : Design and Analysis of Algorithms
Language   : C
Author     : Pratyush Kumar Mallick
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int areElementsUnique(int arr[], int n)
{
    int hash[MAX + 1] = {0};

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0 || arr[i] > MAX)
        {
            printf("Error: Elements should be between 0 and %d\n", MAX);
            return -1;
        }

        if(hash[arr[i]] == 1)
            return 0;   // Duplicate found

        hash[arr[i]] = 1;
    }

    return 1;   // All elements are unique
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = areElementsUnique(arr, n);

    if(result == 1)
        printf("All elements are unique.\n");
    else if(result == 0)
        printf("Duplicate elements found.\n");

    return 0;
}