// Problem: Project Euler #11: Largest product in a grid
// Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler011
// Language: C++

#include <iostream>
#include <array>
#include <algorithm>

constexpr int SIZE = 20;

int main() {
    std::array<std::array<int, SIZE>, SIZE> grid;

    // Input the 20x20 grid
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            std::cin >> grid[i][j];

    long long max_product = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            // Horizontal
            if (j + 3 < SIZE) {
                long long product = 1;
                for (int k = 0; k < 4; ++k)
                    product *= grid[i][j + k];
                max_product = std::max(max_product, product);
            }

            // Vertical
            if (i + 3 < SIZE) {
                long long product = 1;
                for (int k = 0; k < 4; ++k)
                    product *= grid[i + k][j];
                max_product = std::max(max_product, product);
            }

            // Diagonal right
            if (i + 3 < SIZE && j + 3 < SIZE) {
                long long product = 1;
                for (int k = 0; k < 4; ++k)
                    product *= grid[i + k][j + k];
                max_product = std::max(max_product, product);
            }

            // Diagonal left
            if (i + 3 < SIZE && j - 3 >= 0) {
                long long product = 1;
                for (int k = 0; k < 4; ++k)
                    product *= grid[i + k][j - k];
                max_product = std::max(max_product, product);
            }
        }
    }

    std::cout << max_product << '\n';
    return 0;
}
