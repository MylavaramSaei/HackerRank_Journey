// Problem: Project Euler #20: Factorial digit sum
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler020
// Language: c

#include <stdio.h>
#include <string.h>

#define MAX 10000

int factorial[MAX];

// Multiply big integer by x
int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }

    return res_size;
}

int factorial_digit_sum(int n) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int i = 2; i <= n; i++) {
        res_size = multiply(i, res, res_size);
    }

    int sum = 0;
    for (int i = 0; i < res_size; i++) {
        sum += res[i];
    }

    return sum;
}

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", factorial_digit_sum(n));
    }
    return 0;
}
