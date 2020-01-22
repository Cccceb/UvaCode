#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚5-5in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚5-5out.txt", "w", stdout);
#endif 
using namespace std;
string s;
int main() {
	vector<string> dir;
	set<string> mul;
	set<string>ans;
	while (cin >> s) {
		dir.push_back(s);
		mul.insert(s);
	}

	for (int i = 0; i < dir.size(); i++) {
		s = dir[i];

		int j;
		for (j = i+1; j < dir.size(); j++) {

			string b = dir[j];
			if (b.substr(0, s.length()) != s) break;

			string next;
			next = b.substr(s.length());
			if (mul.count(next)) ans.insert(dir[j]);
		}
	}

	for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;


}