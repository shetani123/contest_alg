#include <iostream>
#include <vector>

long long int merge(std::vector<int>& a,int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int inv_count = 0;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = a[i + left];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[j + mid + 1];
    }
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
            inv_count += (n1-i);
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    return inv_count;
}

long long int mergeSort(std::vector<int>& a, int left, int right) {
    long long int inv_count = 0;
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    inv_count += mergeSort(a, left, mid);
    inv_count += mergeSort(a, mid + 1, right);
    inv_count += merge(a, left, mid, right);
    return inv_count;
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    long long int inv_count = 0;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    inv_count += mergeSort(v, 0, n-1);
    std::cout << inv_count;
}