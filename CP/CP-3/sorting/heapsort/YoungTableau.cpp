#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

constexpr int INFINITY = INT_MAX;

template <class T>
class YoungTableau{

    private:
        std::vector<std::vector<T>> table;
        int m, n;

        void youngify(int i, int j) {

            while (true){

                int small_i = i, small_j = j;
                if (i + 1 < m && table[i+1][j] < table[small_i][small_j]) {
                    small_i = i + 1;
                    small_j = j;
                }
                if (j + 1 < n && table[i][j+1] < table[small_i][small_j]) {
                    small_i = i;
                    small_j = j + 1;
                }
                if (small_i != i || small_j != j) {
                    std::swap(table[small_i][small_j], table[i][j]);
                    i = small_i, j = small_j;
                } else {
                    break;
                }
            }
        }

        void UpwardYoungify(int i, int j) {

            int large_i = i;
            int large_j = j;

            if (i > 0 && table[i-1][j] > table[large_i][large_j]) {
                large_i = i - 1;
                large_j = j;
            }
            if (j > 0 && table[i][j-1] > table[large_i][large_j]) {
                large_i = i;
                large_j = j - 1;
            }
            if (large_i != i || large_j != j) {
                std::swap(table[i][j], table[large_i][large_j]);
                UpwardYoungify(large_i, large_j);
            }
        }

    public:

        YoungTableau(int m1, int n1) : m(m1), n(n1) {
            table.resize(m, std::vector<T>(n, INFINITY));
        }

        void insert(T key) {
            table[m-1][n-1] = key;
            UpwardYoungify(m - 1, n - 1);
        }

        T extractMin(void) {
            if (table.empty()) {
                throw std::underflow_error("empty table");
            }
            T min = table[0][0];
            table[0][0] = INFINITY;
            youngify(0, 0);
            return min;
        }

        bool search(T key) {

            /* start from row end, elimnate the rows 
             * by comparing the key with element in that position 
             * same can be done by starting at the column-end
             */
            int i = 0, j = n - 1;
            while ( i < m && j >= 0) {
                if (table[i][j] < key) { // not this row
                    ++i;
                } else if (table[i][j] > key) { // not this column
                    --j;
                } else {
                    return true;
                }
            }
            return false;

        }

        void isYoungifyTableau() {
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (j > 0) {
                            assert(table[i][j-1]  <= table[i][j]);
                        }
                        if (i > 0) {
                            assert(table[i-1][j] <= table[i][j]);
                        }
                        std::cout << table[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
        }
};



int main(int argc, char *argv[]) {

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    srand(time(NULL));
    YoungTableau<int> yt(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = rand() % 101;
            yt.insert(x);
        }
    }
    yt.isYoungifyTableau();
    int ele = rand() % 101;
    std::cout << "search key = " << ele << std::endl;
    std::cout << std::boolalpha << yt.search(ele) << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            yt.extractMin();
        }
    }
    return 0;
}


