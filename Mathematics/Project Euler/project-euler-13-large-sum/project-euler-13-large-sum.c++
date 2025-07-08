// Problem: Project Euler #13: Large sum
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler013
// Language: c++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to add two big integers represented as strings
string add_big_numbers(const string& a, const string& b) {
    string result;
    int carry = 0;
    int len_a = a.size(), len_b = b.size();
    int i = len_a - 1, j = len_b - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit_a = (i >= 0) ? a[i--] - '0' : 0;
        int digit_b = (j >= 0) ? b[j--] - '0' : 0;
        int sum = digit_a + digit_b + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;

    string total = "0";

    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        total = add_big_numbers(total, num);
    }

    // Print first 10 digits of the sum
    cout << total.substr(0, 10) << '\n';

    return 0;
}
