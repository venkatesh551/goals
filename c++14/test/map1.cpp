#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (auto it: mymap)
    std::cout << it.first << " => " << it.second << '\n';

  return 0;
}
