// Problem: Project Euler #21: Amicable numbers
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler021
// Language: c

#include <stdio.h>
#include <string.h>

#define MAX 100001

int divisor_sum[MAX];
int amicable_sum[MAX];

void precompute() {
    // Compute sum of proper divisors
    memset(divisor_sum, 0, sizeof(divisor_sum));
    for (int i = 1; i < MAX; i++) {
        for (int j = 2 * i; j < MAX; j += i) {
            divisor_sum[j] += i;
        }
    }

    // Precompute amicable numbers sum
    memset(amicable_sum, 0, sizeof(amicable_sum));
    for (int i = 2; i < MAX; i++) {
        int a = i;
        int b = divisor_sum[a];
        if (b != a && b < MAX && divisor_sum[b] == a) {
            amicable_sum[a] = a;
        }
    }

    // Prefix sum for fast lookup
    for (int i = 1; i < MAX; i++) {
        amicable_sum[i] += amicable_sum[i - 1];
    }
}

int main() {
    precompute();

    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", amicable_sum[N - 1]);
    }

    return 0;
}
