#include <iostream>


void groupReverse(std::string &str, int g) {

    int n = str.length();
    int x = n/g;
    for (int i = 0; i < n; i += x) {
        for (int j = i, k = i + x - 1; j < k; ++j, --k) {
            std::swap(str[j], str[k]);
        }
    }
}

int main()
{
    int G;
    std::string str;
    while (true) {
        std::cin >> G;
        if (G == 0) {
            break;
        }
        std::cin >> str;
        groupReverse(str, G);
        std::cout << str << std::endl;
    }
    return 0;
}


