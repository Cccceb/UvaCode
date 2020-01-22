#include<iostream>
#include<cctype>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("¿´Í¼Ð´Ê÷in.txt", "r", stdin);
FILE *fout = freopen("¿´Í¼Ð´Ê÷out.txt", "w", stdout);
#endif 
using namespace std;
const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];
void dfs(int r, int c) {
	int i = c;
	cout << buf[r][c] << "(";
	if (r + 1 < n && buf[r + 1][c] == '|') {
		int i = c;
		while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') i--;
		while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0') {
			if (!isspace(buf[r + 3][i])) dfs(r + 3, i);
			i++;
		}
	}
	cout << ")";
}

void solve() {
	n = 0;
	for (;;) {
		fgets(buf[n], maxn, stdin);
		if (buf[n][0] == '#') break;
		else n++;
	}

	cout << "(";
	if (n) {
		for (int i = 0; i < strlen(buf[0]); i++) {
			if (buf[0][i] != ' ') {
				dfs(0, i);
				break;
			}
		}	
	}
	cout << ")" << endl;
}
int main() {
	int T;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &T);
	while (T--)	solve();
	return 0;
}