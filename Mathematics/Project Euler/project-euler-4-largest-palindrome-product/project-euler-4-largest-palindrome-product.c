// Problem: Project Euler #4: Largest palindrome product
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler004
// Language: c

#include <stdio.h>

int is_palindrome(int n) {
    int reversed = 0, original = n;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed == original;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, max_palindrome = 0;
        scanf("%d", &n);

        for (int i = 999; i >= 100; i--) {
            for (int j = i; j >= 100; j--) {
                int product = i * j;
                if (product < n && is_palindrome(product) && product > max_palindrome) {
                    max_palindrome = product;
                }
            }
        }
        
        printf("%d\n", max_palindrome);
    }

    return 0;
}
