#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>


int main()
{
    
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");
    
    int n;
    ifs >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        ifs >> v[i];
    }
    std::sort(v.begin(), v.end());
    int sum = 0, count = 0;
    for (int i = 0; i < n ; ++i) {
        sum += v[i];
        if (sum > 18000) { // 5 hrs in secs
            break;
        }
        count++;
    }
    ofs << count << std::endl;
    return 0; 
}

