#include <iostream>
#include <vector>

//  Left source half is src[begin : mid].
// Right source half is src[mid +1 : end].
// Result is dest[begin : end].

void merge(std::vector<int> &v, std::vector<int> &aux, std::vector<int> &index,
           int begin, int mid, int end) {

    for (int k = begin; k <= end; ++k) {
        aux[k] = index[k];
    }

    int i = begin, j = mid+1;
    
    for (int k = begin; k <= end; ++k) {
        
        if (i <= mid && (j > end || v[aux[i]] <= v[aux[j]])) {
            index[k] = aux[i++];
        } else {
            index[k] = aux[j++];
        }
    }    
}

/*
 * sort the vector src[begin..end] and copy it to dest[src..end]
 */

void mergeSort(std::vector<int> &v, std::vector<int> &aux,
               std::vector<int> &index,
               int begin, int end) {
    if (end <= begin) {
        return;
    }
    int mid = begin + (end - begin)/2;
    /*
     *  Sort the dest[begin..mid] and copy it to src[begin..mid]
     *  Sort the dest[mid+1..end] and copy it to src[mid+1..end]
     *  Now merge the src[begin..mid] and src[mid+1..end] 
     *  into dest vector,
     *  so the dest vector is a sorted one. 
     */
    mergeSort(v, aux, index, begin, mid);
    mergeSort(v, aux, index, mid+1, end);
    merge(v, aux, index, begin, mid, end);    
}

void topDownMergeSort(std::vector<int> &v) {    

    int n = v.size();
    std::vector<int> aux(n), index(n);
    for (int i = 0; i < n; ++i) {
        index[i] = i;
        aux[i] = i;
    }
    /* sort the array/vector aux and copy it to vector v */ 
    mergeSort(v, aux, index, 0, n-1);
    for (const auto &ele: index) {
        std::cout << (1 + ele) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        v.push_back(x);
    }
    topDownMergeSort(v);
    return 0;
}

