#include <iostream>
#include <map>
#include <queue>

void generateMap(std::map<std::string, int> &mp) {

    std::queue<std::string> q;

    for (char c = 'a'; c <= 'z'; ++c) {
        q.push(std::string(1, c));
    }
    std::string s{};
    int count = 1;
    while (!q.empty()) {

        s = q.front();
        q.pop();
        mp[s] = count++;
        if (s.length() < 5) {
            for (char c = 1 + s[s.length() - 1]; c <= 'z'; ++c) {
                q.push(s + c);
            }
        }
    }
}

int main()
{
    std::map<std::string, int> count;
    generateMap(count);
    std::string wrd;
    while (std::cin >> wrd) {
        std::cout << count[wrd] << std::endl;
    }

    return 0;
}
