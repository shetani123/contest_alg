#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double c;
    std::cin >> c;
    double l =0, r = std::sqrt(c);
    for (int i = 0; i < 100; i++) {
        double m = l + (r - l) / 2;
        if (pow(m,2) + std::sqrt(m) < c) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << l;
}