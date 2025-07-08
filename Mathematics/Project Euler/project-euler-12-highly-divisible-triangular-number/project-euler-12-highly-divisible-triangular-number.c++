// Problem: Project Euler #12: Highly divisible triangular number
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler012
// Language: c++

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int count_divisors(long long n) {
    int count = 0;
    long long root = sqrt(n);
    for (long long i = 1; i <= root; ++i) {
        if (n % i == 0) {
            count += 2; // i and n/i
        }
    }
    if (root * root == n) {
        count--; // perfect square correction
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    vector<int> input(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> input[i];
        if (input[i] > max_n) {
            max_n = input[i];
        }
    }

    vector<long long> result(max_n + 1, 0);
    int i = 1;
    long long tri = 0;

    while (*min_element(result.begin() + 1, result.end()) == 0) {
        tri += i;
        int divs = count_divisors(tri);

        for (int d = 1; d <= max_n; ++d) {
            if (result[d] == 0 && divs > d) {
                result[d] = tri;
            }
        }

        ++i;
    }

    for (int n : input) {
        cout << result[n] << '\n';
    }

    return 0;
}
