#include <iostream>
#include <vector>
#include <algorithm>

int main() {
        
    int tc;
    
    std::cin >> tc;
    
    while (tc-- > 0) {
        std::string s;
        std::cin >> s;
        int n = s.size();
        int sCount = 0, mCount = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'm') {
                if (i > 0 && s[i-1] == 's') {
                    s[i-1] = '8';
                } else if (i < (n-1) && s[i+1] == 's') {
                    s[i+1] = '8';
                }
                ++mCount;
            }
        }
        for (auto ch : s) {
            if (ch == 's'){
                 ++sCount;   
            }
        }
        if (sCount == mCount){
            std::cout << "tie" << std::endl; 
        } else if (sCount < mCount) {
            std::cout << "mongooses" << std::endl;
        } else {
            std::cout << "snakes" << std::endl;
        }
    }    
    return 0;
}


