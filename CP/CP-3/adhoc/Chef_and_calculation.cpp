#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        
    int tc;
    
    cin >> tc;
    
    while (tc-- > 0) {
        
        int n;

        cin >> n;
        int ans  = 0, maxIdx = -1;
        bool tie = false;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            vector<int> count(6, 0);
            int sum = k;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                ++count[x-1];
            }
            sort(count.begin(), count.end());
            sum += count[0] * 4 + (count[1] - count[0]) * 2 + (count[2] - count[1]);
            if (ans < sum) {
                ans = sum;
                maxIdx = i;
                tie = false;
            } else if (ans == sum) {
                tie = true;
            }
       }
       if (tie) {
           cout << "tie" << endl;
       } else {
           if (maxIdx == 0) {
               cout << "chef" << endl;
           } else {
               cout << (1 + maxIdx) << endl;
           }
       }
    }    
    return 0;
}


