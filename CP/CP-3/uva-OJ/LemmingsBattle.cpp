#include <iostream>
#include <set>
#include <vector>

void readElements(std::multiset<int, std::greater<int>> &s, int n) {

    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        s.insert(x);
    }

}

void printMultiSet(std::multiset<int, std::greater<int>> &s) {

    for (const auto &ele : s) {
        std::cout << ele << std::endl;
    }

}

void printWinner(std::multiset<int, std::greater<int>> &green,
                 std::multiset<int, std::greater<int>> &blue,
                 int B) {

    while (!(green.empty() || blue.empty())) {
        auto g_it = green.cbegin();
        auto b_it = blue.cbegin();
        int x = std::min(green.size(), blue.size());
        int y = std::min(x, B);
        std::vector<int> first, second;
        for (int i = 0; i < y; ++i) {
            int diff = *g_it - *b_it;
            if (diff > 0) {
                first.emplace_back(diff);
            } else if (diff < 0) {
                second.emplace_back(-diff);
            }
            ++g_it;
            ++b_it;
        }
        green.erase(green.cbegin(), g_it);
        blue.erase(blue.cbegin(), b_it);
        green.insert(first.begin(), first.end());
        blue.insert(second.begin(), second.end());
    }
    if (green.empty() && blue.empty()) {
        std::cout << "green and blue died" << std::endl;
    } else if (green.empty()) {
        std::cout << "blue wins" << std::endl;
        printMultiSet(blue);
    } else {
        std::cout << "green wins" << std::endl;
        printMultiSet(green);
    }
}

int main() 
{
    int tc;
    std::cin >> tc;

    while(tc--) {
        int B, SG, SB;
        std::cin >> B >> SG >> SB;
        std::multiset<int, std::greater<int>> green, blue;
        readElements(green, SG);
        readElements(blue, SB);
        printWinner(green, blue, B);
        if (tc > 0) {
            std::cout <<  std::endl;
        }
    }

    return 0;
}
