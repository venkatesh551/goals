#include <fstream>


int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
 
    int stacksCount = 0, maxHeight = 1, totalCups = 0;
    for (int i = 0; i < n; ++i) {
        int ele;
        ifs >> ele;
        
        if (stacksCount == 0 || ele != 0) {
            ++stacksCount;
        } else if (stacksCount * maxHeight == totalCups) {
            ++maxHeight;
        }
        ++totalCups;
    }
    ofs <<  maxHeight << std::endl;
    return 0;
}


