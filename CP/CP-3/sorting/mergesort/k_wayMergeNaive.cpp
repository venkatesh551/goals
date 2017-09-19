#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void twoWayMerge(std::vector<int> &p, std::vector<int> &dest, int count) {
    
    int m = p.size(), n = count;
    int i = m-1, j = count-1;
    for (int k = m + n -1; k >= 0; --k) {
        if (i >= 0 && (j < 0 || p[i] > dest[j])) {
            dest[k] = p[i--];
        } else {
            dest[k] = dest[j--];
        }
    }
}

/* 
 *  all are fixed-sized vectors 
 */
void kWayMerge(std::vector<std::vector<int>> &v,
               std::vector<int> &result) {

    int k = v.size();
    if (n == 0) {
        return;
    }
    result = v[0];
    for (int i = 1; i < k; ++i) {
        twoWayMerge(v[i], result, i * v[i].size());
    }
    
}


int main () {
    
    int m, n;
    
    std::cin >> m >> n;
    std::vector<std::vector<int>> v(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;           
            std::cin >> x;
            
            v[i].push_back(x);
        }
        std::sort(v[i].begin(), v[i].end());
    }
    std::vector<int> dst(m*n);
    kWayMerge(v, dst);
    for (int i = 0; i < m*n; ++i) {
        std::cout << dst[i] << " ";
    }  
    std::cout << '\n';
    return 0;
}


