#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("unix√¸¡Óin.txt", "r", stdin);
FILE *fout = freopen("unix√¸¡Óout.txt", "w", stdout);
#endif // LOCAL
using namespace std;
void print(const string &in, int len, char extra) {
	
	cout << in;
	for (int i = 0; i < len - in.length(); i++) cout << extra;
}
int main() {
	int n;

	while (scanf("%d", &n) == 1) {
		int m = 0;
		print("", 60, '-');
		cout << endl;
		vector<string> s;
		for (int i = 0; i < n;i++) {
			string in;
			cin >> in;
			s.push_back(in);
			m = max(m, (int)in.length());
		}
		sort(s.begin(), s.end());
		int cols = (60 - m) / (m + 2) + 1;
		int rows = (n - 1) / cols + 1;
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int idx = c * rows + r;
				if (idx < n) print(s[idx], c == cols - 1 ? m : m + 2, ' ');
			}
			cout << endl;
		}
	}
}