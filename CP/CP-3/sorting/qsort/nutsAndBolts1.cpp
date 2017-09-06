#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

void printVector(std::vector<int> &nuts) {

    for (const auto &c : nuts) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}

class Comparator {
  
  public:
       int cmp(int a, int b) {
           if (a * 2 == b) {
               return 0;
           } else if (a * 2 < b) {
               return -1;
           } else {
               return 1;
           }
       }
    
};

int partition(std::vector<int> &v, int low, int high, bool flag, int pivot) {

    int i = low, j = high;
    Comparator compare;
    while (true) {        
        if (flag)
        {
               while (i <= j && compare.cmp(v[i], pivot) == -1)
                    ++i;
        
                if (i <= j && compare.cmp(v[i], pivot) == 0) {
                    std::swap(v[i], v[low]);
                    ++i;
                }
                while (i <= j && compare.cmp(v[j], pivot) == 1)
                    --j;
                if (j <= i) {
                    std::swap(v[j], v[low]);
                    return j;
                }
                std::swap(v[i], v[j]);
            
        } else {
               while (i <= j && compare.cmp(pivot, v[i]) == 1)
                    ++i;
        
                if (i <= j && compare.cmp(pivot, v[i]) == 0) {
                    std::swap(v[i], v[low]);
                    ++i;
                }
                while (i <= j && compare.cmp(pivot, v[j]) == -1)
                    --j;
                if (j <= i) {
                    std::swap(v[j], v[low]);
                    return j;
                }
                std::swap(v[i], v[j]);
        }
    }
    return j;

}


void quicksort (std::vector<int> &nuts,
                std::vector<int> &bolts, int low, int high) {

    if (high <= low) {
        return;
    }
    int mid = (low + high)/2;
    int j = partition(nuts, low, high, true, bolts[mid]);
    partition(bolts, low, high, false, nuts[j]);
    quicksort(nuts, bolts, low, j-1);
    quicksort(nuts, bolts, j+1, high);
    
}


int main() {

    int n = 900;
    std::vector<int> nuts(n), bolts(n);
    for (int i = 0 ; i < n; ++i) {
        nuts[i] = i + 1;
        bolts[i] = 2 * (i + 1);
    }
    quicksort(nuts, bolts, 0, n-1);
    printVector(nuts);
    printVector(bolts);
    return 0;
}


