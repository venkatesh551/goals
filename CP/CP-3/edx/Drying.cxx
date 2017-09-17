#include <fstream>
#include <vector>
#include <algorithm>

int minTimeToDry(std::vector<int> &v, int k)
{

}

int main() {

    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        ifs >> v[i];
    }
    int k;
    ifs >> k;
    ofs << minTimeToDry(v, k) << std::endl;
    return 0;
}


