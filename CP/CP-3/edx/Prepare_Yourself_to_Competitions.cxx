#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

int main ()
{
    
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");
    
    int n;
    
    ifs >> n;
    std::vector<int> pr(n), th(n);
    for (int i = 0; i < n; ++i) {
        ifs >> pr[i];
    }
    for (int i = 0; i < n; ++i) {
        ifs >> th[i];
    }
    int pUsed = false;
    int tUsed = false;
    int minDiff = 1000000, totalSum = 0;
    
    for (int i = 0; i < n ; ++i) {
        int diff;
        if (pr[i] >= th[i]) {
            totalSum += pr[i];
            diff = pr[i] - th[i];
            pUsed = true;
        } else {
            totalSum += th[i];
            diff = th[i] - pr[i];
            tUsed = true;
        }
        if (minDiff > diff){
            minDiff = diff;
        }
    }
    if (pUsed && tUsed){
        ofs << totalSum << std::endl;        
    } else {
        ofs << (totalSum - minDiff) << std::endl;
    }
    
    return 0;
}

