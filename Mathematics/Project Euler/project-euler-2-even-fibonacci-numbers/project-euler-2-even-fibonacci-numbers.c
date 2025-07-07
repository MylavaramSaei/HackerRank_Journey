// Problem: Project Euler #2: Even Fibonacci numbers
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler002
// Language: c

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        long long a = 1, b = 2, sum = 0;
        
        while (b <= n) {
            if (b % 2 == 0)
                sum += b;
            
            long long next = a + b;
            a = b;
            b = next;
        }
        
        printf("%lld\n", sum);
    }
    
    return 0;
}
