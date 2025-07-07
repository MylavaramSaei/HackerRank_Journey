// Problem: Project Euler #10: Summation of primes
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler010
// Language: c

#include <stdio.h>
#include <string.h>

#define MAX 1000001

char is_prime[MAX];
long long prefix_sum[MAX];

void generate_primes() {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    // Build prefix sum of primes
    prefix_sum[0] = 0;
    for (int i = 1; i < MAX; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + (is_prime[i] ? i : 0);
    }
}

int main() {
    int t, n;
    generate_primes();  // One-time preprocessing

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", prefix_sum[n]);
    }

    return 0;
}
