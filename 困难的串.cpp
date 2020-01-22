#include<bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("困难的串in.txt", "r", stdin);
FILE *fout = freopen("困难的串out.txt", "w", stdout);
#endif 
const int maxn = 80;
int cnt, n, l;
int S[maxn];
int dfs(int cur) {
	if (cnt++ == n) {
		int len = 1;
		cout << char('A' + S[0]);
		for (int i = 1; i < cur; i++) {
			if (i&&i % 4 == 0) {
				cout << " ";

			}
			cout << char('A' + S[i]);
			if (i + 1 < cur) {
				if ((i + 1) % 64 == 0) {
					cout << endl;

					cout << char('A' + S[++i]);
					len++;
				}

			}
			len++;
		}
		cout << endl;
		cout << len << endl;
		return 0;
	}
	for (int i = 0; i < l; i++) {
		S[cur] = i;
		int ok = 1;
		for (int j = 1; j * 2 <= cur + 1; j++) {
			int equal = 1;
			for (int k = 0; k < j; k++)
				if (S[cur - k] != S[cur - k - j]) {
					equal = 0;
					break;
				}
			if (equal) {
				ok = 0;
				break;
			}
		}
		if (ok) if (!dfs(cur + 1)) return 0;
	}
	return 1;
}
int main() {

	while (cin >> n >> l && n&&l) {
		cnt = 0;
		memset(S, 0,sizeof(S));
		dfs(0);
	}
}