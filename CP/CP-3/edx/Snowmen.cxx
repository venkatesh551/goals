#include <fstream>
#include <vector>

using LL = long long;

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    std::vector<int> massSum(n+1, 0), parent(n+1, 0);
    LL total = 0;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        
        ifs >> x >> y;
        if (y == 0) {
            parent[i] = parent[parent[x]];
            massSum[i] = massSum[parent[x]];
        } else {
            parent[i] = x;
            massSum[i] = y + massSum[x];
        }
        total += massSum[i];
    }
    ofs << total << std::endl;
    return 0;
}


