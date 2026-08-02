/*
-------------------------------------------------------
Program    : Question 2 
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

int fairCoin()
{
    return rand() % 2;
}

int biasedCoin()
{
    int x = rand() % 100;

    if (x < 70)
        return 1;      // 70% chance of Head
    else
        return 0;      // 30% chance of Tail
}

int main()
{
    int tosses, i;
    int fairHeads = 0, fairTails = 0;
    int biasedHeads = 0, biasedTails = 0;

    srand(time(NULL));

    printf("Enter number of tosses: ");
    scanf("%d", &tosses);

    for(i = 0; i < tosses; i++)
    {
        if(fairCoin())
            fairHeads++;
        else
            fairTails++;

        if(biasedCoin())
            biasedHeads++;
        else
            biasedTails++;
    }

    printf("\n===== Fair Coin =====\n");
    printf("Heads = %d\n", fairHeads);
    printf("Tails = %d\n", fairTails);
    printf("Probability of Head = %.4f\n",
           (float)fairHeads / tosses);

    printf("\n===== Biased Coin (70%% Head) =====\n");
    printf("Heads = %d\n", biasedHeads);
    printf("Tails = %d\n", biasedTails);
    printf("Probability of Head = %.4f\n",
           (float)biasedHeads / tosses);

    return 0;
}