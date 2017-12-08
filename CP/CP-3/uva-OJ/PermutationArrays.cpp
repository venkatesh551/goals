#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>


int main()
{

    int tc;
    std::string line, idxStr, numStr;
    std::getline(std::cin, line);
    tc = atoi(line.data());
    while (tc--) {
        // read a blank line
        std::getline(std::cin, line);
        std::getline(std::cin, idxStr);
        std::getline(std::cin, numStr);
        // 
        std::istringstream iss(idxStr);
        std::vector<int> idxV;
        std::vector<std::string> dV;
        int pos;
        std::string ele;
        while (iss >> pos) {
            idxV.push_back(pos);
        }
        std::istringstream numss(numStr);
        while (numss >> ele) {
            dV.push_back(ele);
        }
        int n = idxV.size();
        std::vector<std::string> permuteV(n);
        for (int i = 0; i < n; ++i) {
            permuteV[idxV[i] - 1] = dV[i];
        }
        for (const auto & ele : permuteV) {
            std::cout << ele << std::endl;
        }
        if (tc > 0)
            std::cout << std::endl;
    }

    return 0;
}


