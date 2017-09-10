#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/*
Sort the first two pairs. [2 comparisons]
Order the pairs w.r.t. their respective larger element. [ 1 comparison]

Call the result [a,b,c,d,e]

We know a<b<d and c<d. Now there are 3 elements less than d,
hence d can't be the median(i.e. 3rd element of the sorted array)

Now, apply the previous technique on remaining elements [a,b, c, e]
We already know  a < b  &&  compare the pair (c, e) [1 comparison]

Order the pairs w.r.t their respective larger element [1 comparison]
We know a < b < e and c < e. So e is not median.

Median is 3rd largest element in this list, so max (b, c)

*/


int medianOf5(std::vector<int> &v) {
    
    if (v[0] > v[1]) {
        std::swap(v[0], v[1]);
    }
    if (v[2] > v[3]) {
        std::swap(v[2], v[3]);
    }
    // Order the pairs by largest element
    if (v[1] > v[3]) {
        std::swap(v[0], v[2]);
        std::swap(v[1], v[3]);
    }
    // Now, v[0] < v[1] < v[3]  and  v[2] < v[3] ; so v[3] is not median
    if (v[2] > v[4]) {
        std::swap(v[2], v[4]);
    }
    // Now, v[0] < v[1] and v[2] < v[4]
    // order the pairs by largest element
    if (v[1] > v[4]) {
        std::swap(v[0], v[2]);
        std::swap(v[1], v[4]);
    }
    // Now, v[0] < v[1] < v[4] and v[2] < v[4] ; so v[4] is not median
    if (v[1] > v[2])
        return v[1];
    else
        return v[2];
}

void printVector(std::vector<int> &v)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

}


int main() {

    std::vector<int> v = {1, 2, 3, 4, 5};
    do {
        std::vector<int> input(v);
        assert(3 == medianOf5(input));
        printVector(v);
    } while (std::next_permutation(v.begin(), v.end()));

    return 0;
}




