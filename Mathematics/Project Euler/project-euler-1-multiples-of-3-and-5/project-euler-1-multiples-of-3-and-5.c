// Problem: Project Euler #1: Multiples of 3 and 5
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001
// Language: c

#include <stdio.h>

// Function to compute sum of multiples of a number below limit
long long sum_of_multiples(int n, int limit) {
    int p = (limit - 1) / n;
    return (long long)n * p * (p + 1) / 2;
}

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        long long sum = 0;
        sum += sum_of_multiples(3, n);
        sum += sum_of_multiples(5, n);
        sum -= sum_of_multiples(15, n); // Subtract multiples of 15 (3 and 5 common)
        printf("%lld\n", sum);
    }

    return 0;
}
