#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

int M = 15;

int partition(std::vector<double> &v, int low, int high)
{
    int i = low + 1, j = high;
    int pivot = v[low];

    while (true)
    {
        while (i <= j && v[i] < pivot){
            ++i;
        }
        while (v[j] > pivot) {
            --j;
        }
        if (i >= j) {
            std::swap(v[low], v[j]);
            break;
        }
        std::swap(v[i], v[j]);
        ++i, --j;
    }
    return j;
}

void InsertionSort(std::vector<double> &v, int low, int high) {

    for (int i = low + 1; i <= high; ++i) {
        int ele = v[i];
        int j = i - 1;
        while (j >= low && ele < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ele;
    }
}

int callcount = 0, depth = 0;

void qsort(std::vector<double> &v, int low, int high, int count)
{
    int n = high - low + 1;
    if (n <= 1) {
        return;
    }
    if ( n <=  M) {
        //std::cout << n << " ";
        InsertionSort(v, low, high);
        return;
    }
    int p = partition(v, low, high);
    ++callcount;
    qsort(v, low, p - 1, 1+count);
    qsort(v, p + 1, high, 1+count);
    depth = std::max(depth, callcount);
    --callcount;
}

void printVector(std::vector<double> &v)
{
    for (const auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    M = atoi(argv[1]);
    int n = atoi(argv[2]);
    std::vector<double> v(n);
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
//        double r = (68.556*rand()/RAND_MAX - 32.768);
        v[i] = i;
    }
    std::vector<double> p(v);
//    std::random_shuffle(v.begin(), v.end());
//    std::shuffle(v.begin(), v.end());
    qsort(v, 0, v.size()-1, 0);
    std::cout << "\ndepth = " << depth << std::endl;
    return 0;
}

