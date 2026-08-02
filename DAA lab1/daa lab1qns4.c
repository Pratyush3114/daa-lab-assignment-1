/*
-------------------------------------------------------
Program    : Question 4
Subject    : Design and Analysis of Algorithms
Language   : C
Author     : Pratyush Kumar Mallick
Institute  : IIIT Bhubaneswar
Semester   : 3rd Semester
-------------------------------------------------------
*/
#include <stdio.h>

long long moves = 0;

// Recursive function for Towers of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move Disk 1 from %c -> %c\n", source, destination);
        moves++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    printf("Move Disk %d from %c -> %c\n", n, source, destination);
    moves++;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\nTotal Moves = %lld\n", moves);
    printf("Theoretical Minimum Moves = %lld\n", (1LL << n) - 1);

    return 0;
}