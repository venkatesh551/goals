#include <fstream>
#include <vector>

using LL = long long;

// Left source half is src[begin : mid].
// Right source half is src[mid +1 : end].
// Result is dest[begin : end].

LL merge(std::vector<int> &src, 
          int begin, int mid, int end, std::vector<int> &dest) {
    int i = begin, j = mid+1;
    LL invCount = 0;
    for (int k = begin; k <= end; ++k) {
        
        if (i <= mid && (j > end || src[i] <= src[j])) {
            dest[k] = src[i++]; 
        } else {
            dest[k] = src[j++];
            invCount += mid - i + 1LL;
        }
    }
    return invCount;
}

/*
 * sort the vector src[begin..end] and copy it to dest[src..end]
 */

LL mergeSort(std::vector<int> &src, 
               int begin, int end, std::vector<int> &dest) {
    
    if (end <= begin) {
        return 0;
    }
    int mid = begin + (end - begin)/2;
    /*
     *  Sort the dest[begin..mid] and copy it to src[begin..mid]
     *  Sort the dest[mid+1..end] and copy it to src[mid+1..end]
     *  Now merge the src[begin..mid] and src[mid+1..end] 
     *  into dest vector, 
     *  so the dest vector is a sorted one. 
     */
    LL left = mergeSort(dest, begin, mid, src);
    LL right = mergeSort(dest, mid+1, end, src);
    return left + right + merge(src, begin, mid, end, dest);
    
}


LL topDownMergeSort(std::vector<int> &v) {
    
    std::vector<int> aux(v);
 
    /* sort the array/vector aux and copy it to vector v */   
    int end = (int)v.size() - 1; 
    return mergeSort(aux, 0, end, v);
}


int main() {

    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    ifs >> n;
    std::vector<int> v(n);    
    for (int i = 0; i < n; ++i) {
        ifs >> v[i];
    }
    ofs << topDownMergeSort(v) << std::endl;
    return 0;
}


