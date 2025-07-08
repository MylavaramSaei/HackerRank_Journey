// Problem: Project Euler #24: Lexicographic permutations
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler024
// Language: c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 13

long long factorial[SIZE + 1];

// Precompute factorials up to 13!
void compute_factorials() {
    factorial[0] = 1;
    for (int i = 1; i <= SIZE; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

// Get Nth lexicographic permutation of "abcdefghijklm"
void get_permutation(long long n) {
    char chars[SIZE + 1] = "abcdefghijklm";
    int used[SIZE] = {0};
    char result[SIZE + 1];
    n--; // convert to 0-based

    for (int i = 0; i < SIZE; i++) {
        long long fact = factorial[SIZE - 1 - i];
        int index = n / fact;
        n %= fact;

        // Find the index-th unused character
        int count = -1;
        for (int j = 0; j < SIZE; j++) {
            if (!used[j]) count++;
            if (count == index) {
                result[i] = chars[j];
                used[j] = 1;
                break;
            }
        }
    }

    result[SIZE] = '\0';
    printf("%s\n", result);
}

int main() {
    compute_factorials();

    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        get_permutation(n);
    }

    return 0;
}
