#include <iostream>
#include <vector>
//#include <algorithm>
auto Sort(const std::vector<int>& a, int maxi) {
    std::vector<int> v(maxi+1,0);
    for (int i : a) {
        v[i]++;
    }
    for (int i = 0; i <= maxi; i++) {
        while (v[i] > 0) {
            std::cout << i << " ";
            v[i]--;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,maxi = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > maxi) maxi = a[i];
    }
    //auto it = std::max_element(a.begin(), a.end());
    //int maxi = *it;
    Sort(a, maxi);
}