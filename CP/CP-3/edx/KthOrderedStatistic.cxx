#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int HoaresPartition(std::vector<int> &v, int left, int right)
{
    srand(time(NULL)); // set the seed for rand() API
    int n = right - left + 1;
    int randomIdx = left + (right - left)/2;
    std::swap(v[randomIdx], v[left]);
    int pivot = v[left];
    int i = left + 1, j = right;

    while (true)
    {
        while (i <= j && v[i] < pivot)
            ++i;
        while (v[j] > pivot)
            --j;
        if (i >= j) {
            std::swap(v[left], v[j]);
            return j;
        }
        std::swap(v[i++], v[j--]);
    }
    return j;

}

void randomizedSelect(std::vector<int> &v, int left, int right, int k) {

    if (right <= left) {
        return;
    }
    int q = HoaresPartition(v, left, right);
    int n = q - left + 1;
    if (k == n) {
        return;
    } else if (k < n) {
        randomizedSelect(v, left, q-1, k);
    } else {
        randomizedSelect(v, q + 1, right, k - n);
    }
}

void InsertionSort(std::vector<int> &v, int left, int right)
{
    for (int i = left+1; i <= right; ++i) {
        int p = v[i];
        int j = i - 1;
        while (j >= left && p < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = p;
    }
}

int main() {

    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n, k1, k2;
    ifs >> n >> k1 >> k2;
    int A, B, C, a1, a2;
    ifs >> A >> B >> C >> a1 >> a2;
    std::vector<int> v(n);
    v[0] = a1;
    v[1] = a2;
    for (int i = 2; i < n; ++i){
        v[i] = A * v[i-2] + B * v[i-1] + C;
    }
    randomizedSelect(v, 0, n-1, k2);
    randomizedSelect(v, 0, k2-1, k1);
    InsertionSort(v, k1-1, k2-1);
    for (int i = k1-1; i < k2; ++i) {
        ofs << v[i] << " ";
    }
    ofs << "\n";
    return 0;
}


