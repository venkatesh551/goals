#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>  
#include <iomanip>

int main ()
{
    
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int table[3][3];
    int v[3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ifs >> table[i][j];
        }
        v[i] = i;
    }
    int maxVal = 0;
    do {
        
        int eff = 0;
        for (int i = 0; i < 3; ++i){
            eff += table[i][v[i]] * table[i][v[i]];
        }
        maxVal = std::max(maxVal, eff);
        
    } while (std::next_permutation(v, v+3));
    
    double result = std::sqrt((double)maxVal);
    ofs.setf(std::ios_base::fixed);
    ofs << result << std::endl;
    return 0;
}

