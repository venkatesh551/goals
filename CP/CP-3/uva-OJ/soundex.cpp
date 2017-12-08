#include <iostream>
#include <vector>


int main() {

    std::vector<std::string> v = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};

    int codeMap[26] = {0};
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (char c: v[i]) {
            codeMap[c - 'A'] = 1 + i;
        }
    }
    std::string str;
    while (std::cin >> str) {
        int prevCode = 0;
        for (char c: str) {
            int curCode = codeMap[c - 'A'];
            if (curCode != 0 && curCode != prevCode) {
                std::cout << curCode;
            }
            prevCode = curCode;
        }
        std::cout << "\n";
    }

    return 0;
}
