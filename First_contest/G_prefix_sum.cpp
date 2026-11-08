#include <iostream>
#include <vector>
#include <numeric>
void sum(std::vector<long long>& p,int n,const std::vector<long long>& a) {
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m;
    std::cin >> n >> m;
    std::vector<long long> a(n+1);
    std::vector<long long>p(n+1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sum(p,n,a);
    for (int i = 0; i < m; i++) {
        int l,r;
        std::cin >> l >> r;
        std::cout << p[r] - p[l-1] << "\n";
    }
}