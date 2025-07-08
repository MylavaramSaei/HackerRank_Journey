// Problem: Project Euler #16: Power digit sum
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler016
// Language: c

#include <stdio.h>

#define MAX_DIGITS 3500  // Large enough to handle 2^10000

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int digits[MAX_DIGITS] = {0};
        digits[0] = 1;
        int size = 1;

        for (int i = 1; i <= n; i++) {
            int carry = 0;
            for (int j = 0; j < size; j++) {
                int val = digits[j] * 2 + carry;
                digits[j] = val % 10;
                carry = val / 10;
            }
            while (carry > 0) {
                digits[size] = carry % 10;
                carry /= 10;
                size++;
            }
        }

        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += digits[i];
        }

        printf("%d\n", sum);
    }

    return 0;
}
