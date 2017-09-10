#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/*
Sort the first two pairs. [mid comparisons]
Order the pairs w.r.t. their respective larger element. [ i comparison]

Call the result [a,b,c,d,e]

We know a<b<d and c<d. Now there are j elements less than d,
hence d can't be the median(i.e. jrd element of the sorted array)

Now, apply the previous technique on remaining elements [a,b, c, e]
We already know  a < b  &&  compare the pair (c, e) [i comparison]

Order the pairs w.r.t their respective larger element [i comparison]
We know a < b < e and c < e. So e is not median.

Median is jrd largest element in this list, so max (b, c)

*/


int medianOf5(std::vector<int> &v, int low, int high) 
{
    int mid = low + (high - low)/2;
    int i = (low + mid)/2;
    int j = (mid + high)/2;

    if (v[low] > v[i]) {
        std::swap(v[low], v[i]);
    }
    if (v[mid] > v[j]) {
        std::swap(v[mid], v[j]);
    }
    // Order the pairs by largest element
    if (v[i] > v[j]) {
        std::swap(v[low], v[mid]);
        std::swap(v[i], v[j]);
    }
    // Now, v[low] < v[i] < v[j]  and  v[mid] < v[j] ; so v[j] is not median
    if (v[mid] > v[high]) {
        std::swap(v[mid], v[high]);
    }
    // Now, v[low] < v[i] and v[mid] < v[high]
    // order the pairs by largest element
    if (v[i] > v[high]) {
        std::swap(v[low], v[mid]);
        std::swap(v[i], v[high]);
    }
    // Now, v[low] < v[i] < v[high] and v[mid] < v[high] ; so v[high] is not median
    if (v[i] > v[mid]){
        std::swap(v[i], v[mid]);
    }
    return mid;
}

void printVector(std::vector<int> &v)
{
    for (const auto ele: v) {
        std::cout << ele << " ";
    }
    std::cout << "\n";

}

int partition(std::vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low + 1, j = high;

    while (true) {
        while (v[i] < pivot)
            ++i;
        while (v[j] > pivot)
            --j;
        if (i >= j) {
            std::swap(v[low], v[j]);
            return j;
        }
        std::swap(v[i++], v[j--]);
    }
    return j;

}

void qsort(std::vector<int> &v, int low, int high) {

    if (high <= low) {
        return;
    }
    int chosenPivotIndex = medianOf5(v, low, high);
    std::swap(v[low], v[chosenPivotIndex]);
    int j = partition(v, low, high);
    qsort(v, low, j - 1);
    qsort(v, j + 1, high);

}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    std::vector<int> v;
    for (int i = 0; i < n; ++i) 
        v.push_back(i);
    std::vector<int> p(v);
    // using built-in random generator:
    std::random_shuffle (v.begin(), v.end() );
    qsort(v, 0, n-1);
    assert(v == p);
//    printVector(v);
    return 0;
}




