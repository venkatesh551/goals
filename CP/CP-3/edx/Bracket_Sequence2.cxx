#include <fstream>
#include <vector>


int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    std::string s;
    char map[128] = {0};
    map[']'] = '[';
    map[')'] = '(';
    for (int i = 0; i < n; ++i) {
        ifs >> s;
        bool good = true;
        int top = 0;
        int j = 0, length = s.size();
        while (good && j < length) {
            if (map[s[j]]) {
                good = top > 0 && (map[s[j++]] == s[--top]);
            } else {
                s[top++] = s[j++];
            }
        }
        if (good && (top == 0))
            ofs << "YES" << std::endl;
        else
            ofs << "NO" << std::endl; 

    }
    return 0;
}


