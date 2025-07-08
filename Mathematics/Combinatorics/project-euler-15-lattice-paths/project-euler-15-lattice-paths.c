// Problem: Project Euler #15: Lattice paths
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler015
// Language: c

#include <stdio.h>

#define MOD 1000000007
#define MAX 1001

long long fact[MAX];

// Function to compute (a^b) % MOD using binary exponentiation
long long mod_pow(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// Precompute factorials up to MAX
void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// Compute C(n, r) % MOD using Fermat's Little Theorem
long long nCr(int n, int r) {
    if (r > n) return 0;
    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % MOD;
    return (numerator * mod_pow(denominator, MOD - 2)) % MOD;
}

int main() {
    compute_factorials();

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", nCr(n + m, n));
    }

    return 0;
}
