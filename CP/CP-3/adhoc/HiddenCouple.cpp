#include <iostream>
#include <string>

int main()
{
    int tc;
    
    std::cin >> tc;
    
    for (int c = 1; c <= tc; ++c){
        
        std::string s;
        std::cin >> s;
        
        int sum  = 0;
        
        for (auto ch : s) {
            sum += ch;
        }
        
        std::cout << "Case " << c << ": ";
        if (sum % 3 == 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}
