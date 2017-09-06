#include <iostream>
#include <vector>


int partition(std::vector<int> &v, int low, int high) {

    std::vector<int> left, right;
    int pivot = v[low];
    for (int i = low + 1; i <= high; ++i) {
        if (v[i] <= pivot) {
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }
    int k = low;
    for (int i = 0; i < left.size(); ++i) {
        v[k++] = left[i];
    }
    int pivot_pos = k;
    v[k++] = pivot;
    for (int i = 0; i < right.size(); ++i) {
        v[k++] = right[i];
    }
    return pivot_pos;
}

void printVector(std::vector<int> &v, int low, int high)
{
    for (int i = low; i <= high; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout <<  "\n";
}


void quicksort(std::vector<int> &v, int low, int high) {

    if (high <= low) {
        return;
    }
    int p = partition(v, low, high);
    quicksort(v, low, p-1);
    quicksort(v, p+1, high);
    printVector(v, low, high);

}


int main() {

    int n; 

    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    quicksort(v, 0, n-1);
    return 0;
}


