#include <iostream>
#include <vector>

void Insert(std::vector<int>& a, int elem) {
    a.push_back(elem);
    int i = a.size() - 1;
    while (i > 0 && a[i] > a[(i-1) / 2]) {
        std::swap(a[i], a[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void Extract(std::vector<int>& a) {
    std::cout << a[0] << "\n";
    a[0] = a.back();
    a.pop_back();
    int i = 0;
    int size = a.size();
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;
        if (right < size && a[right] > a[left]) {
            largest = right;
        }
        if (a[i] >= a[largest]) {
            break;
        }
        std::swap(a[i], a[largest]);
        i = largest;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a;
    int cmd,elem;
    for (int i = 0; i < n; i++) {
        std::cin >> cmd;
        if (cmd == 0) {
            std::cin >> elem;
            Insert(a,elem);
        }
        else if (cmd == 1) Extract(a);
    }
    return 0;
}