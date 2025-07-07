// Problem: Project Euler #7: 10001st prime
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler007
// Language: c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200000  // Precompute primes up to this value
#define MAX_PRIMES 15000  // Store this many primes

int primes[MAX_PRIMES];  // Store the first N primes
char is_prime[MAX];      // Boolean sieve array

void generate_primes() {
    int count = 0;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i < MAX && count < MAX_PRIMES; i++) {
        if (is_prime[i]) {
            primes[count++] = i;
            for (int j = i * 2; j < MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int main() {
    int t, n;
    generate_primes();  // Precompute all primes up to MAX

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", primes[n - 1]);  // 1-based indexing
    }

    return 0;
}
