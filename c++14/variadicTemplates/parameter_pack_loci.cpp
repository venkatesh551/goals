#include <iostream>
#include <map>
#include <vector>

template <typename... Ts>
void createMap(Ts... args) {
    std::map<Ts...> mp;
    mp.insert (std::pair<Ts...>(args...));
    auto lst = {std::pair<Ts...>(args, 'a')...};
    for (auto ele : lst) {
        mp.insert(ele);
    }
    for (auto ele : mp) {
        std::cout << ele.first << " " << ele.second << std::endl;
    }
    std::vector<int>  lst2  =  {(Ts) args... };
    for (int i = 0; i < lst2.size(); ++i){
        std::cout << lst2[i] << " ";
    }
    std::cout << "\n";
}
int main() {
    createMap(1, 'd');
    return 0;
}


