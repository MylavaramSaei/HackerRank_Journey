// Problem: Project Euler #18: Maximum Path Sum I
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler018
// Language: c

#include <stdio.h>

int triangle[100][100];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int T;
    scanf("%d", &T); // Number of test cases

    while (T--) {
        int n;
        scanf("%d", &n); // Rows in triangle

        // Read triangle
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                scanf("%d", &triangle[i][j]);
            }
        }

        // Bottom-up DP to find max path sum
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        printf("%d\n", triangle[0][0]); // Final answer
    }

    return 0;
}
