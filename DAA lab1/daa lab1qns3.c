/*
-------------------------------------------------------
Program    : Question 3 
Subject    : Design and Analysis of Algorithms
Language   : C
Author     : Pratyush Kumar Mallick
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Bubble Sort with Early Termination
int bubbleSortOptimized(int arr[], int n)
{
    int i, j, comparisons = 0, swapped;

    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    return comparisons;
}

// Bubble Sort without Early Termination
int bubbleSortNormal(int arr[], int n)
{
    int i, j, comparisons = 0;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }

    return comparisons;
}

int main()
{
    srand(time(NULL));

    printf("Array Size\tOptimized\tNormal\n");
    printf("-----------------------------------------\n");

    for(int n = 100; n <= 1000; n += 100)
    {
        int arr1[n], arr2[n];

        for(int i = 0; i < n; i++)
        {
            int value = rand() % 10000;
            arr1[i] = value;
            arr2[i] = value;
        }

        int c1 = bubbleSortOptimized(arr1, n);
        int c2 = bubbleSortNormal(arr2, n);

        printf("%5d\t\t%8d\t%8d\n", n, c1, c2);
    }

    return 0;
}