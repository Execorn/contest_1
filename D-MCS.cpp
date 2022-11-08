#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

void MCS(std::string& ans, const std::string& a, const std::string& b) {
    const int len_a = a.size();
    const int len_b = b.size();

    const int len_ans = len_b + 1;
    std::vector<int> x(len_ans, 0), y(len_ans);

    std::vector<int>* prev = &x;
    std::vector<int>* cur  = &y;

    int max_len = 0;
    int ans_idx = 0;

    for (int i = len_a - 1; i >= 0; --i) {
        for (int j = len_b - 1; j >= 0; --j) {
            int &match = (*cur)[j];
            if (a[i] != b[j]) {
                match = 0;
            } else {
                const int length = 1 + (*prev)[j + 1];
                if (length > max_len) {
                    max_len = length;
                    ans_idx = i;
                }

                match = length;
            }
        }

        swap(prev, cur);
    }

    ans = a.substr(ans_idx, max_len);
}



int main() {
    std::string a, b, ans;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    MCS(ans, a, b);
    std::cout << ans << std::endl;

    return 0;
}