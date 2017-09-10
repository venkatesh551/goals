#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>

using pii = std::pair<int, int>;

void printVector(std::vector<int> &v)
{
    for (const auto ele : v)
        std::cout << ele << " ";
    std::cout << "\n";

}


int partition(std::vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low + 1, j = high;

    while (true) {
        while (i <= j && v[i] < pivot)
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

void qsort(std::vector<int> &v) {

    std::stack<pii> st;
    st.push({0, v.size() - 1});

    while (!st.empty()) {
        const pii top_ele = st.top();
        st.pop();
        int low = top_ele.first, high = top_ele.second;
        if (high - low > 0) {
            int j = partition(v, low, high);
            if ((high - j) > (j - low)){
                st.push({j + 1, high});
                st.push({low, j - 1});
            } else {
                st.push({low, j - 1});
                st.push({j + 1, high});
            }
        }
    }

}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    std::vector<int> v;
    for (int i = 0; i < n; ++i) 
        v.push_back(i);
    std::vector<int> p(v);
    // using built-in random generator:
    std::random_shuffle (v.begin(), v.end() );
    qsort(v);
    assert(v == p);
    // printVector(v);
    return 0;
}




