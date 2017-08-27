#include <fstream>
#include <stack>
#include <iostream>

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    std::string s;    
 
    ifs >> n;
    std::getline(ifs, s);
    std::getline(ifs, s);
    int len = s.size();
    std::stack<int> st;
    for (int i = 0; i < len; i += 2) {
        // std::cout << s[i] << std::endl;
        if (std::isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            switch (s[i]) {
                case '+':
                    st.push(x + y); break;
                case '-':
                    st.push(x - y); break;
                case '*':
                    st.push(x * y); break;
            }
            
        }
    }    
    ofs << st.top() << std::endl;   
    return 0;
}


