#include <iostream>
#include <vector>

//  Left source half is src[begin : mid].
// Right source half is src[mid +1 : end].
// Result is dest[begin : end].
void merge(std::vector<int> &src, 
           int begin, int mid, int end, std::vector<int> &dest) {

    int i = begin, j = mid+1;
    
    for (int k = begin; k <= end; ++k) {
        
        if (i <= mid && (j > end || src[i] <= src[j])) {
            dest[k] = src[i++]; 
        } else {
            dest[k] = src[j++];
        }
    }    
    
}


/*
 * sort the vector src[begin..end] and copy it to dest[src..end]
 */

void mergeSort(std::vector<int> &src,
               int begin, int end, std::vector<int> &dest) {
    
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
    mergeSort(dest, begin, mid, src);
    mergeSort(dest, mid+1, end, src);
    merge(src, begin, mid, end, dest);    
}


void topDownMergeSort(std::vector<int> &v) {
    
    std::vector<int> aux(v);
 
    /* sort the array/vector aux and copy it to vector v */   
    int end = (int)v.size() - 1; 
    mergeSort(aux, 0, end, v);
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




