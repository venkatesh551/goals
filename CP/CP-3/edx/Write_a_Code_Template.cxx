#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>


int getDistance(std::pair<int, int> &p1, std::pair<int, int> &p2)
{
    return std::max(abs(p1.first - p2.first),
                    abs(p1.second - p2.second));

}


int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int W, H;
    ifs >> W >> H;
    std::vector<std::string> keyBoard(H);
    std::map<char, std::pair<int, int>> positionMap;
    for (int i = 0; i < H; ++i) {
            ifs >> keyBoard[i];
            for (int j = 0; j < W; ++j)
                positionMap[keyBoard[i][j]] = std::make_pair(H - i, 1+j); 
    }
    std::string languageName; // name of the language
    std::string templateStart; // template Start
    std::string line; // template End
    std::getline (ifs, line); // read empty newline
    std::string bestTemplateLanguage;
    int minScore = (int) 1e9 + 7;
    while (true) {
        std::getline(ifs, languageName);
        if (ifs.eof()) {
            break;
        }
        std::getline(ifs, templateStart);
        int curScore = 0;
        char previousChar = 0;
        while (true) {
            std::getline (ifs, line);
            if (line == "%TEMPLATE-END%") {
                break;
            }
            int n = line.size();
            for (int i = 0; i < n; ++i){
                char curChar = line[i];
                if (!(std::isspace(curChar))) {
                    if (previousChar != 0) {
                        curScore += getDistance(positionMap[previousChar],
                                                positionMap[curChar]);
                    }
                    previousChar = curChar;
                }
            }
        }
        if (curScore < minScore) {
            bestTemplateLanguage = languageName;
            minScore = curScore;
        }
    }
    ofs << bestTemplateLanguage << std::endl;
    ofs << minScore << std::endl;
    return 0;
}

