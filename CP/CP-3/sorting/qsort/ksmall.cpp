#include <iostream>
#include <algorithm>
#include <vector>

const int MAXSIZE = 5000000;
unsigned int array[MAXSIZE];

void randomize(unsigned a,unsigned b,unsigned mod)
{
    for( int i=0 ; i < MAXSIZE ; i++ )
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        array[i] = ((a << 16) + b) % mod;
    }
}

int partition(unsigned int low, unsigned int high)
{
    int mid  = low + (high - low) /2;
    std::swap(array[low], array[mid]);
    unsigned int pivot = array[low];

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
    unsigned int a, b, mod, k;
    std::cin >> a >> b >> mod >> k;
    randomize(a, b, mod);
    int low = 0, high = MAXSIZE - 1;
    k--;
    while (low <= high) {
        int j = partition(low, high);
        if (j < k) {
            low = j + 1;
        } else if (j > k) {
            high = j - 1;
        } else {
            std::cout << array[j] << std::endl;
            return 0;
        }
     }
    return 0;
}


