// Problem: Project Euler #3: Largest prime factor
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler003
// Language: c

#include <stdio.h>

long long largest_prime_factor(long long n) {
    long long maxPrime = -1;

    // Remove all the 2s
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // Try all odd numbers from 3 upwards
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n", largest_prime_factor(n));
    }

    return 0;
}
