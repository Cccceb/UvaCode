#include <iostream>
#include <string>
#include<set>
#include<map>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("³ý·¨in.txt", "r", stdin);
FILE *fout = freopen("³ý·¨out.txt", "w", stdout);
#endif 
using namespace std;
map<string, string> ans;
set<char> dis;
int main() {
	int n;
	int first = 1;
	while (cin >> n && n) {
		if (first) first = 0; else cout << endl;
		ans.clear();
		for (int i = 1234; i < 100000; i++) {
			string a = to_string(i);
			int j = i * n;
			string b = to_string(j);
			if (a.length() == 4) a = "0" + a;
			if (a.length() + b.length() > 10) break;
			for (int i = 0; i < a.size(); i++)
				dis.insert(a[i]);
			for (int i = 0; i < b.size(); i++)
				dis.insert(b[i]);

			if (dis.size() == 10)
				ans[b] = a;
			dis.clear();
		}
		if (ans.empty()) cout << "There are no solutions for " << n << "." << endl;
		else
			for (auto it = ans.begin(); it != ans.end(); it++)
				cout << it->first << " / " << it->second << " = " << n << endl;
	}

	return 0;
}