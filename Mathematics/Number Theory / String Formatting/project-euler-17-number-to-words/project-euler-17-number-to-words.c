// Problem: Project Euler #17: Number to Words
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler017
// Language: c

#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

const char *ones[] = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

const char *tens[] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"
};

const char *scales[] = {
    "", "Thousand", "Million", "Billion", "Trillion"
};

// Print numbers less than 1000
void convert_hundreds(int num) {
    if (num >= 100) {
        printf("%s Hundred", ones[num / 100]);
        num %= 100;
        if (num != 0) printf(" ");
    }
    if (num >= 20) {
        printf("%s", tens[num / 10]);
        if (num % 10 != 0) {
            printf(" %s", ones[num % 10]);
        }
    } else if (num > 0) {
        printf("%s", ones[num]);
    }
}

// Main print function
void convert_number(ull n) {
    if (n == 0) {
        printf("Zero\n");
        return;
    }

    int groups[5] = {0};  // trillions, billions, millions, thousands, units
    int group_count = 0;

    // Split into 3-digit groups
    while (n > 0) {
        groups[group_count++] = n % 1000;
        n /= 1000;
    }

    int printed = 0;
    for (int i = group_count - 1; i >= 0; i--) {
        if (groups[i] != 0) {
            if (printed) printf(" ");
            convert_hundreds(groups[i]);
            if (strlen(scales[i]) > 0) {
                printf(" %s", scales[i]);
            }
            printed = 1;
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ull n;
        scanf("%llu", &n);
        convert_number(n);
    }
    return 0;
}
