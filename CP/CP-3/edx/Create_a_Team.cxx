#include <fstream>
#include <vector>
#include <utility>
#include <cmath>  
#include <iomanip>

int main ()
{
    
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int table[3][3];
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ifs >> table[i][j];
        }
    }
    
    int maxVal = 0;
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            if (j != k) {
                int l = 3 - j - k;
                int efficiency =  table[0][j] * table[0][j] + 
                                  table[1][k] * table[1][k] + 
                                  table[2][l] * table[2][l] ;
                maxVal = std::max(maxVal, efficiency);
            }
        }        
    }
    double result = std::sqrt((double)maxVal);
    ofs << std::setprecision(20) << result << std::endl;
    return 0;
}

