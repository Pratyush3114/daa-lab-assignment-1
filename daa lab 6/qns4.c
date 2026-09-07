#include <stdio.h>
#include <limits.h>

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter dimensions:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int dp[N][N];

    // Cost is 0 when there is only one matrix
    for (int i = 1; i < N; i++) {
        dp[i][i] = 0;
    }

    // length is the chain length
    for (int length = 2; length < N; length++) {

        for (int i = 1; i < N - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n",
           dp[1][N - 1]);

    printf("Time Complexity: O(N^3)\n");
    printf("Space Complexity: O(N^2)\n");

    return 0;
}