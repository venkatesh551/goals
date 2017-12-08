#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <sstream>

using pii = std::pair<int, int>;

struct Info{

    Info(int base, int size, int count, std::vector<pii> &rngs) : 
        baseAddress(base), elementSize(size), D(count), v(rngs) {
    }
    Info (const Info &other) {
        baseAddress = other.baseAddress;
        elementSize = other.elementSize;
        D = other.D;
        v = other.v;
    }
    Info() {
    }
    int baseAddress;
    int elementSize;
    int D;
    std::vector<pii> v;
};

int main() {

    int N, R;
    std::cin >> N >> R;
    std::string arrayName;
    int baseAddress, elementSize, D;
    std::map<std::string, Info> arrayInfo;
    for (int i = 0; i < N; ++i) {
        std::cin >> arrayName >> baseAddress;
        std::cin >> elementSize >> D;
        std::vector<pii> v;
        for (int j = 0; j < D; ++j) {
            int lower, upper;
            std::cin >> lower >> upper;
            v.push_back({lower, upper});
        }
        arrayInfo[arrayName] = Info(baseAddress, elementSize, D, v);
    }
    std::cin.ignore();
    std::string line;
    int x;
    for (int i = 0; i < R; ++i) {
        std::getline(std::cin, line);
        std::istringstream ss(line);
        std::vector<int> indices;
        ss >> arrayName;
        while (ss >> x) {
            indices.push_back(x);
        }
        Info &curArray = arrayInfo[arrayName];
        int D = curArray.D;
        std::vector<int> C(D+1);
        C[D] = curArray.elementSize;
        for (int j = D-1; j > 0; --j) {
            C[j] = C[j+1] * 
                (curArray.v[j].second - curArray.v[j].first + 1);
        }
        C[0] = curArray.baseAddress;
        for (int j = 1; j <= D; ++j) {
            C[0] -= C[j] * curArray.v[j-1].first;
        }
        int physicalAddress = C[0];
        for (int j = 1; j <= D; ++j) {
            physicalAddress += C[j] * indices[j-1];
        }
        int n = indices.size();
        std::cout << arrayName << "[";
        for (int j = 0; j < n-1; ++j) {
            std::cout << indices[j] << ", ";
        }
        std::cout << indices[n-1] << "] = ";
        std::cout << physicalAddress << std::endl;
    }

    return 0;
}

