#include <iostream>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    std::deque<int> a1;
    std::deque<int> a2;
    for (int i = 0; i < q; i++) {
        char s;
        std::cin >> s;
        if (s == '+') {
            int x;
            std::cin >> x;
            a1.push_back(x);
            while (!a2.empty() && a2.back() > x) {
                a2.pop_back();
            }
            a2.push_back(x);
        }
        else if (s == '-') {
            int val = a1.front();
            a1.pop_front();
            if (a2.front() == val) {
                a2.pop_front();
            }
        }
        if (a1.empty()) {
            std::cout << "-1" << "\n";
        } else {
            std::cout << a2.front() << "\n";
    }
    }
    return 0;
}