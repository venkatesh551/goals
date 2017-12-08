#include <iostream>
#include <vector>
#include <map>

int main() {

    int num;
    std::map<int, int> mp;
    std::vector<int> v;
    while (std::cin >> num) {
        if (mp.count(num) == 0) {
            v.push_back(num);
        }
        ++mp[num];
    }
    for (auto const ele: v) {
        std::cout << ele << " " << mp[ele] << std::endl;
    }
    return 0;
}
