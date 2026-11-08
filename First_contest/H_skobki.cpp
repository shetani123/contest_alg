#include <iostream>
#include <stack>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::deque<char> st;
    std::string s;
    std::cin >> s;
    if (s.length() % 2 != 0) {
        std::cout << "NO";
        return 0;
    }
    else if (s.empty()) {
        std::cout << "YES";
        return 0;
    }
    else {
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push_back(s[i]);
            } else {
                if (st.empty()) {
                    std::cout << "NO";
                    return 0;
                }
                char t = st.back();
                if ((s[i] == ')' && t == '(') || (s[i] == '}' && t == '{') || (s[i] == ']' && t == '[')) {
                    st.pop_back();
                } else {
                    std::cout << "NO";
                    return 0;
                }
            }

        }
    }
    if (st.empty()) std::cout << "YES";
    else std::cout << "NO";
}