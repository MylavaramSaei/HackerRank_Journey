// Problem: Project Euler #14: Longest Collatz sequence
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler014
// Language: c++

#include <stdio.h>

#define LIMIT 5000001

int collatz[LIMIT] = {0};
int best_start[LIMIT] = {0};

// Computes Collatz length using memoization
int get_collatz_length(long long n) {
    if (n < LIMIT && collatz[n] != 0)
        return collatz[n];

    long long next;
    if (n % 2 == 0)
        next = n / 2;
    else
        next = 3 * n + 1;

    int length = 1 + get_collatz_length(next);

    if (n < LIMIT)
        collatz[n] = length;

    return length;
}

int main() {
    collatz[1] = 1;
    best_start[1] = 1;

    for (int i = 2; i < LIMIT; ++i) {
        get_collatz_length(i);

        if (collatz[i] >= collatz[best_start[i - 1]]) {
            best_start[i] = i;
        } else {
            best_start[i] = best_start[i - 1];
        }
    }

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", best_start[n]);
    }

    return 0;
}
