// Problem: Project Euler #23: Non-abundant sums
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler023
// Language: c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 100001

int abundant[LIMIT] = {0};
int is_sum_of_abundants[LIMIT] = {0};

// Function to compute sum of proper divisors
int sum_of_divisors(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

void precompute() {
    // Mark abundant numbers
    for (int i = 12; i < LIMIT; i++) {
        if (sum_of_divisors(i) > i) {
            abundant[i] = 1;
        }
    }

    // Compute all sums of two abundant numbers
    for (int i = 12; i < LIMIT; i++) {
        if (!abundant[i]) continue;
        for (int j = i; j + i < LIMIT; j++) {
            if (abundant[j]) {
                is_sum_of_abundants[i + j] = 1;
            }
        }
    }
}

int main() {
    precompute();

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n < LIMIT && is_sum_of_abundants[n]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
