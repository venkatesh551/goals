#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int> &v) {
    
    for (const auto &x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;    
}


void insertionSort(std::vector<int> &v) 
{
    int n = v.size();

    for (int i = 1; i < n; ++i) {
        int j = i;
        int temp = v[i];
        while (j > 0 && v[j-1] > temp) {
            v[j] = v[j-1];
            j--;
            printVector(v);
        }
        v[j] = temp;
        if (j != i) {
            printVector(v);
        }
    }
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
