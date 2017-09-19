#include <iostream>
#include <vector>

void merge(std::vector<int> &v, std::vector<int> &aux,
           int begin, int mid, int end) {
               
    int i = begin, j = mid;
    
    for (int k = begin; k < end; ++k) {
        if (i < mid && (j >= end || v[i] <= v[j])) {
            aux[k] = v[i++];
        } else {
            aux[k] = v[j++];
        }
    }
}


void BottomUpMergeSort(std::vector<int> &v, std::vector<int> &aux) {
    
    int n = v.size();
    
    for (int width = 1; width < n; width *= 2) {
        // two subarrays of size- width are merged at a time
        for (int i = 0; i < n; i += 2*width) { 
            merge(v, aux, i, std::min(i + width, n), std::min(i + 2 * width, n));
        }
        v = aux;
    }
        
}


int main() 
{
    
    int n;
    
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    std::vector<int> aux(n);
    BottomUpMergeSort(v, aux);
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}


