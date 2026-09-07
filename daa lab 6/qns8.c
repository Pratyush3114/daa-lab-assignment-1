#include <stdio.h>

long long cost = 0;

/* Reverse p[i...j] */
void reverse(int p[], int i, int j) {

    cost += (j - i + 1);

    while(i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;

        i++;
        j--;
    }
}

/* Rotate:
   p[first...middle-1] and p[middle...last-1]

   Example:
   A B | C D
   becomes
   C D | A B
*/
void rotate(int p[], int first, int middle, int last) {

    if(first == middle || middle == last)
        return;

    reverse(p, first, middle - 1);
    reverse(p, middle, last - 1);
    reverse(p, first, last - 1);
}

/* Divide-and-conquer merge */
void merge(int p[], int left, int middle, int right) {

    if(left >= middle || middle >= right)
        return;

    /* Already sorted */
    if(p[middle - 1] < p[middle])
        return;

    int firstCut;
    int secondCut;

    if(middle - left > right - middle) {

        firstCut = left + (middle - left) / 2;

        int value = p[firstCut];

        secondCut = middle;

        while(secondCut < right && p[secondCut] < value)
            secondCut++;

    }
    else {

        secondCut = middle + (right - middle) / 2;

        int value = p[secondCut];

        firstCut = left;

        while(firstCut < middle && p[firstCut] <= value)
            firstCut++;
    }

    int newMiddle = firstCut + (secondCut - middle);

    rotate(p, firstCut, middle, secondCut);

    merge(p, left, firstCut, newMiddle);
    merge(p, newMiddle, secondCut, right);
}

/* Merge sort */
void mergeSort(int p[], int left, int right) {

    if(right - left <= 1)
        return;

    int middle = (left + right) / 2;

    mergeSort(p, left, middle);
    mergeSort(p, middle, right);

    merge(p, left, middle, right);
}

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int p[n];

    printf("Enter permutation:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    mergeSort(p, 0, n);

    printf("Sorted permutation:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\nTotal reversal cost = %lld\n", cost);

    return 0;
}