#include <iostream>

using namespace std;

int main() {

	int tc;

	cin >> tc;

	while (tc--) {
		int n;
		
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cout << (2 * i + 1) << " ";
		}
		cout << endl;

	}

	return 0;
}
