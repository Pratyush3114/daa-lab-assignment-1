#include <stdio.h>
#include <math.h>

int main() {
    int a[100], n;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // (i) Maximum
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];

    printf("Maximum = %d\n", max);

    // (ii) First and Second Largest
    int first = a[0], second = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > first) {
            second = first;
            first = a[i];
        }
        else if(a[i] > second && a[i] != first)
            second = a[i];
    }

    printf("First Largest = %d\n", first);
    printf("Second Largest = %d\n", second);

    // (iii) Mean
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];

    printf("Mean = %.2f\n", (float)sum / n);

    // (iv) Median - first sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    if(n % 2 == 1)
        printf("Median = %d\n", a[n/2]);
    else
        printf("Median = %.2f\n",
               (a[n/2-1] + a[n/2]) / 2.0);

    // (v) Standard Deviation
    float mean = (float)sum / n;
    float variance = 0;

    for(int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance = variance / n;

    printf("Standard Deviation = %.2f\n", sqrt(variance));

    // (vi) Mode
    int mode = a[0], maxCount = 0;

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++)
            if(a[i] == a[j])
                count++;

        if(count > maxCount) {
            maxCount = count;
            mode = a[i];
        }
    }

    printf("Mode = %d\n", mode);

    // (vii) Remove duplicates
    printf("After removing duplicates: ");

    for(int i = 0; i < n; i++) {
        int duplicate = 0;

        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                duplicate = 1;
                break;
            }
        }

        if(!duplicate)
            printf("%d ", a[i]);
    }

    printf("\n");

    // (viii) Reverse
    int i = 0, j = n-1;

    while(i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    printf("Reversed array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    // (ix) Partition using pivot
    int pivot;
    printf("Enter pivot: ");
    scanf("%d", &pivot);

    printf("Partitioned array: ");

    for(i = 0; i < n; i++)
        if(a[i] < pivot)
            printf("%d ", a[i]);

    printf("%d ", pivot);

    for(i = 0; i < n; i++)
        if(a[i] >= pivot && a[i] != pivot)
            printf("%d ", a[i]);

    return 0;
}