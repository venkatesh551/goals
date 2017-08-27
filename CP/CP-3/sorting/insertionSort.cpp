#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<int> &v) 
{
    int n = v.size();
    std::vector<int> unsorted(v);
    for (int i = 1; i < n; ++i) {
        int j = i;
        int temp = v[i];
        while (j > 0 && v[j-1] > temp) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
    for (const auto &ele : unsorted) {
        std::vector<int>::iterator low = 
            std::lower_bound(v.begin(), v.end(), ele);
        std::cout << 1 + (low - v.begin()) << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int n;
     
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    insertionSort(v);  
    
    return 0;
}
