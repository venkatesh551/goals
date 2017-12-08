#include <iostream>
#include <map>
#include <vector>

using map_str = std::map<std::string, std::string>;

void printVector(std::vector<std::string> &v, char prefix) {

    int n = v.size();
    if (n == 0) {
        return;
    }
    std::cout << prefix;
    for (int i = 0; i < n-1; ++i) {
        std::cout << v[i] << ',';
    }
    std::cout << v[n-1] << std::endl;
}


void compareAndPrintDicts(map_str &d1, map_str &d2)
{

    std::vector<std::string> newKeys, removedKeys, changedKeys;
    auto d1_it = d1.cbegin();
    auto d2_it = d2.cbegin();

    while (d1_it != d1.cend() && d2_it != d2.cend()) {

        if (d1_it->first  < d2_it->first) {
            removedKeys.emplace_back(d1_it->first);
            d1_it++;
        } else {
            if (d2_it->first == d1_it->first) {
                if (d1_it->second != d2_it->second) {
                    changedKeys.emplace_back(d1_it->first);
                }
                ++d1_it;
            } else {
                newKeys.emplace_back(d2_it->first);
            }
            ++d2_it;
        }
    }
    while ( d1_it != d1.cend()) {
        removedKeys.emplace_back(d1_it->first);
        ++d1_it;
    }

    while ( d2_it != d2.cend()) {
        newKeys.emplace_back(d2_it->first);
        ++d2_it;
    }
    if (newKeys.size() == 0 && removedKeys.size() == 0 &&
        changedKeys.size() == 0) {
        std::cout << "No changes" << std::endl;
        return;
    }
    printVector(newKeys, '+');
    printVector(removedKeys, '-');
    printVector(changedKeys, '*');
}

std::vector<std::string> split(std::string &s, char delim) {

    std::vector<std::string> result;
    std::string word {""};

    int n = s.length();

    for (int i = 1; i < n; ++i) {
        char c = s[i];
        if (c == delim) {
            result.emplace_back(word);
            word = "";
        } else {
            word += c;
        }
    }

    if (word.length() > 0) {
        result.emplace_back(word);
    }

    return result;
}

void constructDict(map_str &d, std::string &s)
{
    auto result = split(s, ',');
    for (auto const &str : result) {
        size_t pos = str.find_first_of(':');
        if (pos != std::string::npos) {
            const auto key = str.substr(0, pos);
            const auto val = str.substr(pos + 1);
            d[key] = val;
        }
    }
}


int main()
{
    int tc;
    std::cin >> tc;
    std::string first, second;
    while (tc--) {
        std::cin >> first >> second;
        first.pop_back();
        second.pop_back();
        map_str dict1, dict2;
        constructDict(dict1, first);
        constructDict(dict2, second);
        compareAndPrintDicts(dict1, dict2);
        std::cout << std::endl;
    }

    return 0;
}

