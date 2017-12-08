#include <iostream>

constexpr int min(int n, int p)
{
  return n < p ? n : p;
}

template<typename... Args>
constexpr
int min(int n, Args... args)
{
    return min(n, min(args...));
}

int main(int argc, char *argv[])
{
  constexpr int val = min(4, 5, 6, 42, 7, 3, 6);

  static_assert(val == 3, "min is incorrect");

//  min(1);
  std::cout << val << std::endl;
}



