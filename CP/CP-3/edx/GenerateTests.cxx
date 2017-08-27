#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>


/* For a number to be highly composite 
 * it has to have prime factors as small as possible,
 * but not too many of the same
 */

int getMinimumHighlyCompositeNumber(const int n)
{
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    int primesCount = primes.size();
    int maxDivisorCount = 0, minhcn = -1;

    for (int i = 2; i <= n; ++i){
        
        int value = i;
        int divisorCount = 1;
        for (int j = 0; j < primesCount && value >= primes[j]; ++j) {
            int exponent = 0;
            while (value % primes[j] == 0) {
                ++exponent;
                value /= primes[j];
            }
            divisorCount *= (exponent + 1);
        }
        if (maxDivisorCount < divisorCount) {
            maxDivisorCount = divisorCount;
            minhcn = i;
        }
        
    } 

    return minhcn;
}

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    int ans = n - getMinimumHighlyCompositeNumber(n) + 1;
    ofs << ans << std::endl;
    return 0;
}

