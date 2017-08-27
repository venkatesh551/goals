#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>  
#include <iomanip>


int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int a, b, c;

    ifs >> a >> b >> c;

    ofs.setf(std::ios_base::fixed);
    ofs << std::setprecision(10) << (a + b + c)/6.0 << std::endl;
    return 0;
}

