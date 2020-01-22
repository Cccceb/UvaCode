#include<bits/stdc++.h>
#define maxn 105
#pragma warning(disable :4996)
#define LOCAL
#ifdef LOCAL	
FILE *fin = freopen("环状序列in.txt", "r", stdin);
FILE *fout = freopen("环状序列out.txt", "w", stdout);
#endif
using namespace std;
set<string> dir;
int main() {
	int T;
	cin >> T; getchar();
	string line;
	while (T--)
	{
		dir.clear();
		getline(cin, line);
		for (int i = 0; i < line.length(); i++) {
			string s;
			for (int j = 0; j < line.length(); j++) 
				s += line[(i + j) % line.length()];
			dir.insert(s);
		}
		cout << *dir.begin() << endl;
	}


	return 0;
}
