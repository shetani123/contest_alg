#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> heap(n+1,0);
    for (int i = 1; i < n+1; i++) {
        std::cin >> heap[i];
    }
    for (int i = 1; i <= n+1; i++) {
        if (i * 2 <= n) {
            if (heap[i] <= heap[i*2]){}
            else {
                std::cout << "NO";
                return 0;
            }
        }
        if (2*i + 1 <= n) {
            if (heap[i] <= heap[i*2 + 1]){}
            else {
                std::cout << "NO";
                return 0;
            }
        }
    }
    std::cout << "YES";
}