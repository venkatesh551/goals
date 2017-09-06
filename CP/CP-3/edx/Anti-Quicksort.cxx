#include <fstream>
#include <vector>

int main()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;

    ifs >> n;
    std::vector<int> v(n);
    int k = 0, high = n-1;
    for (int i = 0; i < n; ++i) {
        int mid = (i + high)/2;
        if (v[mid] == 0) {
            v[mid] = i+1;
        } else {
            v[k++] = i+1;
        }
    }
    for (const auto x: v) {
        ofs << x << " ";
    }
    ofs << "\n";
    return 0; 
}


