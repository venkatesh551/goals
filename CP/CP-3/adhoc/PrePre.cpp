#include <algorithm>
#include <iostream>

int main()
{
    
    std::string s, t;
    
    std::cin >> s >> t;
    
    int i = 0;
    for(int j = 0; i < s.size() && j < t.size(); ++j){
            if (s[i] == t[j]) {
                ++i;
            }
    }
    std::cout << i << std::endl; 

    return 0;
}
