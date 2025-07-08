// Problem: Project Euler #19: Counting Sundays
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler019
// Language: c

#include <stdio.h>

typedef long long ll;

int is_leap(ll y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Returns weekday of given date (0 = Sunday ... 6 = Saturday)
int get_weekday(ll y, int m, int d) {
    if (m <= 2) {
        m += 12;
        y--;
    }
    ll k = y % 100;
    ll j = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    return (h + 6) % 7; // Convert to 0 = Sunday, ..., 6 = Saturday
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        ll y1, m1, d1;
        ll y2, m2, d2;
        scanf("%lld %lld %lld", &y1, &m1, &d1);
        scanf("%lld %lld %lld", &y2, &m2, &d2);

        int count = 0;
        ll y = y1;
        int m = m1;

        while (y < y2 || (y == y2 && m <= m2)) {
            if (!((y == y1 && m == m1 && 1 < d1) || (y == y2 && m == m2 && 1 > d2))) {
                int weekday = get_weekday(y, m, 1);
                if (weekday == 0) count++;
            }

            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
