#include <iostream>
#include <algorithm>
#include <vector>


int partition(std::vector<int> &array, int low, int high)
{
    int mid  = low + (high - low) /2;
    std::swap(array[low], array[mid]);
    int pivot = array[low];

    int i = low + 1, j = high;

    while (true) {
        while (i <= j && array[i] < pivot)
            ++i;
        while (array[j] > pivot)
            --j;
        if (j <= i) {
            std::swap(array[j], array[low]);
            return j;
        }
        std::swap(array[i++], array[j--]);
    }
    return j;
}


int main()
{
    std::vector<int> v = {-1, 2, 0};
    int n = v.size(), k = 1;
    int low = 0, high = n - 1;
    k = n - k;
    while (low <= high) {
        int j = partition(v, low, high);
        std::cout << k << " " << j << " " << v[j] << std::endl;
        if (j < k) {
            low = j + 1;
        } else if (j > k) {
            high = j - 1;
        } else {
            std::cout << v[j] << std::endl;
            return 0;
        }
     }
    return 0;
}


