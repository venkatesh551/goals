#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main ()
{
	string line;
	getline(cin, line);
    int tc = stoi(line);
	while (tc--) {
		getline(cin, line);
		istringstream iss(line); // Turn the string into a stream.
		vector<string> v{istream_iterator<string>{iss},
             		      istream_iterator<string>{}
				     };
        // cerr << v.size() << endl;
		int n = v.size() - 1;
		string & lastName = v[n];
        for (auto & c: lastName)
            c = tolower(c);
		lastName[0] = toupper(lastName[0]);
		
		for (int i = 0 ; i < n; ++i) {
			string & name = v[i];
			name[0] = toupper(name[0]);
			cout << name[0] << ". ";
		}
		cout << lastName << endl;
	}

	return 0;
}
