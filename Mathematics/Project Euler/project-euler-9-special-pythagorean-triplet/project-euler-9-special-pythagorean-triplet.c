// Problem: Project Euler #9: Special Pythagorean triplet
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler009
// Language: c

#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        int max_product = -1;

        for (int a = 1; a < n / 3; a++) {
            int b = (n * (n - 2 * a)) / (2 * (n - a));
            int c = n - a - b;

            if (a * a + b * b == c * c) {
                int product = a * b * c;
                if (product > max_product)
                    max_product = product;
            }
        }

        printf("%d\n", max_product);
    }

    return 0;
}
