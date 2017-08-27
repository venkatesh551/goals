#include <fstream>
#include <set>

using LL = long long;

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    std::multiset<int> cups {};
    for (int i = 0; i < n; ++i) {
        int ele;
        ifs >> ele;
        int value = 1; // new-stack if ele != 0
        if (ele == 0) {
            if (!cups.empty()) {
                auto it = cups.begin();
                value = 1 + *it; // increment smallest element
                cups.erase(it);
            }
        }
        cups.insert(value);
    }
    ofs << *(cups.rbegin()) << std::endl;
    return 0;
}


