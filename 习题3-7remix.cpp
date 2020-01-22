#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ3-7in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ3-7out.txt", "w", stdout);
#endif 
using namespace std;
int xl[1005][4];
string base = "ACGT";
int to_index(char c) {
	return base.find(c);
}
int main() {
	int m, n,T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		memset(xl, 0, sizeof(xl));
		for (int i = 0; i < m; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < n; j++)
				xl[j][to_index(line[j])]++;
		}
		string ans;
		int dis = 0;
		for (int i = 0; i < n; i++) {
			int zd = 0;
			int w = 0;
			for (int j = 0; j < 4; j++) {
				if (xl[i][j] > zd) {
					zd = xl[i][j];
					w = j;
				}
			}
			for (int j = 0; j < 4; j++) {
				if (j != w) dis += xl[i][j];
			}
			ans += base[w];
		}
		cout << ans << endl;
		cout << dis << endl;


	}
	
}