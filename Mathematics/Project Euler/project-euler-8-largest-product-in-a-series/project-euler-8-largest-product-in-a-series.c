// Problem: Project Euler #8: Largest product in a series
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler008
// Language: c

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        char number[n + 1];
        scanf("%s", number);

        long long max_product = 0;

        for (int i = 0; i <= n - k; i++) {
            long long product = 1;
            for (int j = 0; j < k; j++) {
                product *= number[i + j] - '0';  // Convert char to int
            }
            if (product > max_product)
                max_product = product;
        }

        printf("%lld\n", max_product);
    }

    return 0;
}
