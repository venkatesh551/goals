#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

void printVector(std::vector<int> &nuts, std::vector<char> &bolts) {

    for (const auto &c : nuts) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    for (const auto &c : bolts) {
        std::cout << c << " ";
    }
    std::cout << "\n";

}

int partition(std::vector<int> &nuts,
              std::vector<char> &bolts, int low, int high) {

    int pivot = nuts[low];
    int index = 0;
    for (int i = low, j = high; true ; ) {
        while (i <= j && bolts[i] < pivot) {
            ++i;
        }
        if (i <= j && bolts[i] ==  pivot) {
            std::swap(bolts[i], bolts[low]);
            ++i;
        }
        while (i <= j && (bolts[j] > pivot)) {
            --j;
        }
        if (j <= i) {
            index = j;
            break;
        }
        std::swap(bolts[i], bolts[j]);
    }
    char p = bolts[low];
    for (int i = low+1, j = high; ; ) {
        while (nuts[i] < p) {
            ++i;
        }
        while (nuts[j] > p) {
            --j;
        }
        if (j <= i) {
            break;
        }
        std::swap(nuts[i++], nuts[j--]);
    }
    return index;

}


void quicksort (std::vector<int> &nuts,
                std::vector<char> &bolts, int low, int high) {

    if (high <= low) {
        return;
    }
    int j = partition(nuts, bolts, low, high);
    quicksort(nuts, bolts, low+1, j);
    quicksort(nuts, bolts, j+1, high);
    
}


int main() {


    int n ;

    std::cin >> n;
    std::vector<int> nuts(n);
    std::vector<char> bolts(n);

    for (int i = 0; i < n; ++i) {
        nuts[i] = bolts[i] = 65 +i;
    }
    int i = 0;
    do {
        quicksort(nuts, bolts, 0, n-1);
        for (int j = 0; j < n; ++j) {
            if (nuts[j] != bolts[j]) {
                assert(false);
            }
        }
        std::next_permutation(nuts.begin(), nuts.end());
    } while (i++ <  100);
    return 0;
}


