// Problem: Project Euler #22: Names scores
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler022
// Language: c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 5200
#define MAX_LEN 12

char names[MAX_NAMES][MAX_LEN];
int scores[MAX_NAMES];
int N;

int compare(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int get_name_value(const char* name) {
    int sum = 0;
    for (int i = 0; name[i]; i++) {
        sum += (name[i] - 'A' + 1);
    }
    return sum;
}

int binary_search(const char* key) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(names[mid], key);
        if (cmp == 0) return mid;
        if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", names[i]);
    }

    // Sort names alphabetically
    qsort(names, N, sizeof(names[0]), compare);

    // Precompute scores
    for (int i = 0; i < N; i++) {
        int value = get_name_value(names[i]);
        scores[i] = (i + 1) * value;
    }

    // Handle queries
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        char query[MAX_LEN];
        scanf("%s", query);
        int idx = binary_search(query);
        if (idx != -1)
            printf("%d\n", scores[idx]);
        else
            printf("0\n"); // not found
    }

    return 0;
}
