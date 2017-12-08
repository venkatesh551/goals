#include <iostream>
#include <string>
#include <set>

using namespace std;

void read_input(set<string> &p)
{
	for (int i = 0; i < 4; ++i)
	{
		string s;
		cin >> s;
		p.insert(s);
	}
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		set<string> p, q;
		read_input(p);
		read_input(q);
		int cnt = 0;
		for(set<string>::iterator it = p.begin(); it != p.end(); ++it)
		{
			if (q.count(*it) != 0)
				++cnt;
	
		}
		if (cnt > 1)
			cout << "similar" << endl;
		else
			cout << "dissimilar" << endl;

	}
	return 0;
}
