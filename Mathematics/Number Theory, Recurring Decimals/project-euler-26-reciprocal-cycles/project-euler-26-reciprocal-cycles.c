// Problem: Project Euler #26: Reciprocal cycles
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler026
// Language: c

#include <stdio.h>

#define MAX_N 10001

int cycle_lengths[MAX_N];

// Function to find recurring cycle length for 1/d
int get_cycle_length(int d) {
    int remainder_position[d];
    for (int i = 0; i < d; i++)
        remainder_position[i] = -1;

    int value = 1, pos = 0;

    while (value != 0) {
        value %= d;
        if (remainder_position[value] != -1) {
            return pos - remainder_position[value];
        }
        remainder_position[value] = pos;
        value *= 10;
        pos++;
    }

    return 0;
}

// Precompute best d < N with longest recurring cycle
void precompute() {
    int max_length = 0;
    int best_d = 0;

    for (int i = 2; i < MAX_N; i++) {
        int curr_len = get_cycle_length(i);
        if (curr_len > max_length) {
            max_length = curr_len;
            best_d = i;
        }
        cycle_lengths[i] = best_d;
    }
}

int main() {
    int T, N;
    precompute();
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        printf("%d\n", cycle_lengths[N - 1]);
    }

    return 0;
}
