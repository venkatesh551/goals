#include <iostream>
/*
template<typename... Args>
int sum(Args... args);
*/

template<>
int sum() {
    return 0;
}

template<typename T, typename... Args>
int sum(T n, Args... args)
{
    return n + sum(args...); // this is not recursion
}

int main()
{
  int val = sum(5, 10, 15, 20);
  std::cout << val << std::endl;
}



/*
 
 int sum(int _a, int _b) {
    return -1;
}

*/

