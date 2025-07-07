// Problem: Project Euler #5: Smallest multiple
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler005
// Language: c

#include <stdio.h>

// Function to compute Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Function to compute Least Common Multiple (LCM)
long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        long long result = 1;
        
        for (int i = 2; i <= n; i++) {
            result = lcm(result, i);
        }
        
        printf("%lld\n", result);
    }

    return 0;
}
