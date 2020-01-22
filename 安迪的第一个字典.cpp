#include<iostream>
#include<string>
#include<sstream>
#include<set>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("°²µÏin.txt", "r", stdin);
FILE *fout = freopen("°²µÏout.txt", "w", stdout);
#endif 
using namespace std;
set<string> dir;
int main() {
	string s, buf;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			else s[i] = ' ';
			
		}
		stringstream ss(s);
		while (ss >> buf) dir.insert(buf);
	}

	for (set<string>::iterator it = dir.begin(); it != dir.end(); it++)
		cout << *it << endl;
}