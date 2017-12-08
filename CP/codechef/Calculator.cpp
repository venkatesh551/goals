#include <iostream>

using namespace std;

using LL = long long;

int T, N, B;

LL max_val(LL x) {
    return (N - x * B) * x;
}

int main() {

    cin >> T;
    while (T-- > 0) {
        cin >> N >> B;
        LL x = N / (2 * B);
        cout << max(max_val(x), max_val(x + 1)) << endl;
    }
    return 0;
}


