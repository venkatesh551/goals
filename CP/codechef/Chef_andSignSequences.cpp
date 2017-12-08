#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main ()
{
    int tc;
    
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int lessthanCount = 0, greaterthanCount = 0;
        int ans = 0;
        for (auto & ch : s) {
            if (ch == '<') {
                lessthanCount++;
                ans = max(ans, max(greaterthanCount, lessthanCount));
                greaterthanCount = 0;
            } else if (ch == '>') {
                greaterthanCount++;
                ans = max(ans, max(greaterthanCount, lessthanCount));
                lessthanCount = 0;
            }           
        }
        ans = max(ans, max(greaterthanCount, lessthanCount)); 
        cout << (ans + 1) << endl;
    }

    return 0;
}


