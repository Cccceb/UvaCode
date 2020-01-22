#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ6-2in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ6-2out.txt", "w", stdout);
#endif 
using namespace std;
int n, m, kase = 0;
int main() {
	while (cin >> m && m) {
		cout << "S-Tree #" << ++kase << ":" << endl;
		getchar();
		string s;
		getline(cin, s);
		

		getline(cin, s);

		int first = s.length();
		map<long long , char> leaf;
		for (int i = 0; i < s.length(); i++) leaf[first++] = s[i];


		cin >> n; getchar();
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			int k = 1;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == '0') k *= 2;
				else k = k * 2 + 1;
			}
			cout << leaf[k];
		}
		cout << endl<<endl;
	}

}