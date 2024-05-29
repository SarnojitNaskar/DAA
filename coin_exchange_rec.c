#include <stdio.h>

// Recursive function to count the number of ways to make the sum
int count(int coins[], int n, int sum) {
    if (sum == 0)
        return 1;
    if (sum < 0 || n <= 0)
        return 0;

    // Include the current coin or exclude it
    return count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1]);
}

int main() {
    int coins[] = {1, 2, 3}; // Denominations of coins
    int n = sizeof(coins) / sizeof(coins[0]); // Number of coin types
    int sum = 5; // Target sum

    printf("Number of ways to make %d using given coins: %d\n", sum, count(coins, n, sum));
    return 0;
}

