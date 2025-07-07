// Problem: Project Euler #6: Sum square difference
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler006
// Language: c

#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        
        long long sum_of_n = (long long)n * (n + 1) / 2;
        long long square_of_sum = sum_of_n * sum_of_n;

        long long sum_of_squares = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long difference = square_of_sum - sum_of_squares;

        printf("%lld\n", difference);
    }

    return 0;
}
