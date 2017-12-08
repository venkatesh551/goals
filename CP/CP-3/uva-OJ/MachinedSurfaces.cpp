#include <iostream>
#include <vector>

int getNoOfVoidSpaces(std::vector<std::string> &v) {

    int n = v.size(), minVal = 25;
    std::vector<int> spaceCount(n);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 25; ++j) {
            if (v[i][j] == ' ') {
                ++cnt;
            }
        }
        spaceCount[i] = cnt;
        minVal = std::min(cnt, minVal);
    }
    int sum = 0;
    for (auto const ele : spaceCount) {
        sum += ele - minVal;
    }
    return sum;
}

int main() {

    int n;
    while (std::cin >> n && n > 0) {
        std::vector<std::string> v(n);
        std::cin.ignore();
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, v[i]);
        }
        std::cout << getNoOfVoidSpaces(v) << std::endl;
    }
    return 0;
}

