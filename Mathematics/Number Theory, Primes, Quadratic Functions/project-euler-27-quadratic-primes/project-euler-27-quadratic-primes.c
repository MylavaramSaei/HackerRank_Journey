// Problem: Project Euler #27: Quadratic primes
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler027
// Language: c

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_A 1000
#define MAX_B 1000

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int consecutive_primes(int a, int b) {
    int n = 0;
    while (true) {
        int val = n * n + a * n + b;
        if (!is_prime(val)) break;
        n++;
    }
    return n;
}

int main() {
    int max_a, max_b;
    scanf("%d %d", &max_a, &max_b);

    int max_count = 0;
    int best_a = 0, best_b = 0;

    for (int a = -max_a + 1; a < max_a; a++) {
        for (int b = -max_b; b <= max_b; b++) {
            int count = consecutive_primes(a, b);
            if (count > max_count) {
                max_count = count;
                best_a = a;
                best_b = b;
            }
        }
    }

    printf("%d\n", best_a * best_b);
    return 0;
}
