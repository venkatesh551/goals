#include <iostream>
#include <set>

using namespace std;

int main () {
    
    set < int > st;
    for (int i = 1; i <= 10; ++i) {
        st.insert(st.end(), i);
    }
    for (auto ele: st) {
        cout << ele << endl;
    }
    
    return 0;
}
