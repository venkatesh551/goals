#include <iostream>
#include <string>

int main() 
{
    int tc;
    
    std::cin >> tc;
    while (tc--) {
        std::string s;
        
        std::cin >> s;
        
        int n = s.length()/2;
        
        for (int i = 0; i < n; i+= 2){
            std::putchar(s[i]);
        }
        std::putchar('\n');
    }
    
    return 0;
}

