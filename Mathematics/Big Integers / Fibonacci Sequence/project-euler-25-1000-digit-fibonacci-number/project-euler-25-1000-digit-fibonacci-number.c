// Problem: Project Euler #25: 1000-digit Fibonacci number
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler025
// Language: c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 5001
#define MAX_FIBS 25000

char *fib[MAX_FIBS];
int index_for_digits[MAX_DIGITS];

void add_big(const char *a, const char *b, char *res) {
    int len_a = strlen(a), len_b = strlen(b);
    int i = len_a - 1, j = len_b - 1, k = 0, carry = 0;
    char temp[MAX_DIGITS] = {0};

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    for (int l = 0; l < k; l++) {
        res[l] = temp[k - l - 1];
    }
    res[k] = '\0';
}

void precompute() {
    for (int i = 0; i < MAX_FIBS; i++) {
        fib[i] = malloc(MAX_DIGITS);
        fib[i][0] = '\0';
    }

    strcpy(fib[1], "1");
    strcpy(fib[2], "1");
    index_for_digits[1] = 1; // F(1) and F(2) both have 1 digit

    for (int i = 3; i < MAX_FIBS; i++) {
        add_big(fib[i - 1], fib[i - 2], fib[i]);
        int len = strlen(fib[i]);
        if (len < MAX_DIGITS && index_for_digits[len] == 0) {
            index_for_digits[len] = i;
        }
        if (len >= MAX_DIGITS - 1)
            break;
    }
}

int main() {
    precompute();

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", index_for_digits[n]);
    }

    // Cleanup
    for (int i = 0; i < MAX_FIBS; i++) {
        free(fib[i]);
    }

    return 0;
}
