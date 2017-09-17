#include <iostream>
#include <vector>
#include <algorithm>

void qsort(std::vector<int> &v, int left, int right, int &cnt)
{
    int pivot = v[(left + right)/2];
    int i = left, j = right;

    do {
        while (v[i] < pivot){
            ++cnt;
            ++i;
        }
        while (v[j] > pivot){
            ++cnt;
            --j;
        }
        cnt += 2;
        if (i > j){
            break;
        }
        std::swap(v[i++], v[j--]);
    } while (i <= j);
    if (left < j) {
        qsort(v, left, j, cnt);
    }
    if (i < right) {
        qsort(v, i, right, cnt);
    }
}

void printVector(std::vector<std::vector<int>> &vv) {

    for (const auto &v: vv) {
        for (int ele: v) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }

}

int main(){

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }

    int max = 0;
    std::vector<std::vector<int>> result;

    do {
        std::vector<int> p(v);
        int cnt = 0;
        qsort(p, 0, n-1, cnt);
        if (max < cnt) {
            result.clear();
            max = cnt;
            result.emplace_back(v);
        } else if (max == cnt) {
            result.emplace_back(v);
        }
    } while(std::next_permutation(v.begin(), v.end()));
    printVector(result);
    std::cout << max << std::endl;
    return 0;
}



