#include <iostream>
#include <vector>

/*
 * sort the vector v[begin..end]
 */

void mergeSort(std::vector<int> &v, 
               int begin, int end, std::vector<int> &temp) {
    
    if (end <= begin) {
        return;
    }
    int mid = begin + (end - begin)/2;
    
    /* Merge sort with lot of copy opearations */
    
    mergeSort(v, begin, mid, temp);
    mergeSort(v, mid+1, end, temp);
    for (int i = begin, j = 1 + mid, k = begin; k <= end; ++k) {
        
        if (i <= mid && (j > end || v[i] <= v[j])) {
            temp[k] = v[i++];
        } else {
            temp[k] = v[j++];
        }    
    }
    for (int i = begin; i <= end; ++i) {
        v[i] = temp[i];
    }
}


void topDownMergeSort(std::vector<int> &v) {
    
    std::vector<int> aux(v.size());
 
    /* sort the array/vector aux and copy it to vector v */   
    int end = (int)v.size() - 1; 
    mergeSort(v, 0, end, aux);
}


int main() {
    std::vector<int> v;
    int num;
    while (std::cin >> num) {
        v.push_back(num);
    }
    topDownMergeSort(v);
    for (const auto &ele: v) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    return 0;
}




