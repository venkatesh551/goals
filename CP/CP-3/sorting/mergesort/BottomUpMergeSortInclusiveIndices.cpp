#include <iostream>
#include <vector>

void merge(std::vector<int> &v, std::vector<int> &aux,
           int begin, int mid, int end) {
               
    int i = begin, j = mid + 1;
    
    for (int k = begin; k <= end; ++k) {
        if (i <= mid && (j > end || v[i] <= v[j])) {
            aux[k] = v[i++];
        } else {
            aux[k] = v[j++];
        }
    }
}


void BottomUpMergeSort(std::vector<int> &v) {
    
    int n = v.size();
    std::vector<int> aux(n);
    for (int width = 1; width < n; width *= 2) {
        // two subarrays of size- width are merged at a time
        for (int i = 0; i + width < n; i += 2*width) {
            // don't run merge opration if second interval is empty
            merge(v, aux, i, i + width -1, std::min(i + 2 * width - 1, n-1));
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
    BottomUpMergeSort(v);
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}


