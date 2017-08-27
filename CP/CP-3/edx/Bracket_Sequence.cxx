#include <fstream>
#include <vector>
#include <stack>

bool isCorrectSequence(std::string &s) {
    
    int n = s.size();
    std::stack<char> st;
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (ch == '(' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;            
            } else {
                char top_ele = st.top();
                st.pop();
                if (ch == ']' && top_ele == '[') {
                    
                } else if (ch == ')' && top_ele == '(') {
                    
                } else {
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    std::string s;    
    for (int i = 0; i < n; ++i) {
        ifs >> s;
        if (isCorrectSequence(s))
            ofs << "YES" << std::endl;
        else
            ofs << "NO" << std::endl; 
    }
    return 0;
}

