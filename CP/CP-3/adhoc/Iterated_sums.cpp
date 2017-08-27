#include <iostream>


int sum(int n)
{
    int temp = n * (n + 1) * (2 * n + 1);
    return temp/6;
}


int main()
{
    
    int a, b;
    
    std::cin >> a >> b;
    
    int ans = sum(b) - sum(a-1);
    
    std::cout << ans << std::endl;
    
    return 0;
}
