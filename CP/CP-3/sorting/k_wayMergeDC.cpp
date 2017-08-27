#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> twoWayMerge(std::vector<int> &p, std::vector<int> &q) {
    int m = p.size(), n = q.size();
    int i = 0, j = 0;
    std::vector<int> result;
    for (int k = 0; k < (m + n); ++k) {
        if (i < m && (j >= n || p[i] <= q[j])) {
            result.push_back(p[i++]);
        } else {
            result.push_back(q[j++]);
        }
    }
    return result;
}

/* 
 *  all are fixed-sized vectors 
 */

std::vector<int> kWayMerge(std::vector<std::vector<int>> &v, int start, int end) {
    
    if (end <= start) {
        return v[start];
    } else if (end - start == 1) {
        return twoWayMerge(v[start], v[end]);
    } else {
        int mid = (start + end)/2;
        auto left = kWayMerge(v, start, mid);
        auto right = kWayMerge(v, mid+1, end);
        return twoWayMerge(left, right);
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
    std::vector<int> result = kWayMerge(v, 0, m-1);
    for (auto x : result) {
        std::cout << x << " ";
    }  
    std::cout << '\n';

    return 0;
}


