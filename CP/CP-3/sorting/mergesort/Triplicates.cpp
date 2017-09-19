#include <iostream>
#include <vector>

int minIdx(int x, int y, int z) {
    
    if (x < y && x < z) {
        return 0;
    } else if (y < z) {
        return 1;
    } else {
        return 2;
    }
}

int findTriplicate(std::vector<int> &a, std::vector<int> &b,
                   std::vector<int> &c) {
    
    int i = 0, j = 0, k = 0;
    int n = a.size();
    while (i < n && j < n && k < n) {
        
        if (a[i] == b[j] && a[i] == c[k]) {
            return a[i];
        }
        int idx = minIdx(a[i], b[j], c[k]);
        if (idx == 0) {
            ++i;
        } else if (idx == 1) {
            ++j;
        } else {
            ++k;
        }
    }
    return -1;
}


int main()
{
    std::vector<int> a = {1, 4, 5}, b = {3, 4, 5}, c = {1, 2, 5};
    std::cout << findTriplicate(a, b, c) << std::endl;   
    
    return 0;
}
