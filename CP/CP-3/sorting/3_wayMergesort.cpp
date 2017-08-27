#include <iostream>
#include <vector>
#include <algorithm>

int getIntervalSize(int beg, int end)
{
    return (end - beg + 1)/3;
}

void twoWayMerge(std::vector<int> &v, std::vector<int> &aux, int beg, int mid, int end) {
    
    for (int k = beg; k <= end; ++k) {
        aux[k] = v[k];
    }
    int i = beg, j =  mid + 1;
    for (int k = beg; k <= end; ++k) {
        if (i <= mid && (j > end || aux[i] <= aux[j])) {
            v[k] = aux[i++];
        } else {
            v[k] = aux[j++];
        }
    }

}

void threeWayMerge(std::vector<int> &v, std::vector<int> &aux, int beg, int end) {
    
    int x = getIntervalSize(beg, end);
    twoWayMerge(v, aux, beg, beg + x - 1, beg + 2 * x -1);
    twoWayMerge(v, aux, beg, beg + 2 * x -1, end);
        
}

void threeWayMergeSort(std::vector<int> &v, std::vector<int> &aux, int beg, int end) {
    
    if (end - beg <= 1) {
        if (v[beg] > v[end]) {
            int temp = v[beg];
            v[beg] = v[end];
            v[end] = temp;
        }
        return;
    }
    int x = getIntervalSize(beg, end);
    threeWayMergeSort(v, aux, beg, beg + x -1);
    threeWayMergeSort(v, aux, beg + x, beg + 2 * x -1);  
    threeWayMergeSort(v, aux, beg + 2 * x, end);    
    threeWayMerge(v, aux, beg, end);
}

void sort(std::vector<int> &v) {
    
    int n = v.size();
    std::vector<int> aux(n);
    threeWayMergeSort(v, aux, 0, n-1);
    for (const auto ele : v) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

int main()
{   
    int num;
    std::vector<int> v;
    while (std::cin >> num) {
        v.push_back(num);
    }
    sort(v);
    return 0;
}
