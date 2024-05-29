#include <stdio.h>

int N = 1000; // Maximum value for sum
int SUM = 1000; // Maximum value for sum

// Memoization table to store results of subproblems
int dp[1001][1001];

int count(int coins[], int n, int sum) {
    if (sum == 0)
        return dp[n][sum] = 1;
    if (n == 0 || sum < 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    return dp[n][sum] = count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1]);
}

int main() {
    int coins[] = {1, 2, 3}; // Denominations of coins
    int n = sizeof(coins) / sizeof(coins[0]); // Number of coin types
    int sum = 5; // Target sum
    int i, j;

    // Initialize memoization table
    for (i = 0; i <= n; i++)
        for (j = 0; j <= sum; j++)
            dp[i][j] = -1;

    printf("Number of ways to make %d using given coins: %d\n", sum, count(coins, n, sum));
    return 0;
}

