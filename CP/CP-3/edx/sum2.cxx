#include <fstream>

using LL = long long;

int main()
{
    
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");
    
    int  a, b;
    ifs >> a >> b;
    ofs << (a + (LL) b * b) << std::endl;
    return 0; 
}


