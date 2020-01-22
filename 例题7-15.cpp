#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("ÀýÌâ7-15in.txt", "r", stdin);
FILE *fout = freopen("ÀýÌâ7-15out.txt", "w", stdout);
using namespace std;
inline int getr(int r, int c);
inline int getc(int r, int c);
inline void get_cnt();
const int maxn = 5;
void dfs(int d);
int getNext();
int n, maxd, cnt, sum;
bool sticks[2 * maxn*(maxn + 1) + 1];
int Size[625];
int full[625];
int in[625][2 * maxn*(maxn + 1) + 1];
int main() {
	int T, k, tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d\n%d", &n, &k);
		memset(sticks, 1, sizeof(sticks));
		memset(in, 0, sizeof(in));
		while (k--) {
			scanf("%d", &tmp);
			sticks[tmp] = false;
		}
		sum = 2 * n*(n + 1);
		maxd = sum;
		get_cnt();
		dfs(0);
		printf("%d\n", maxd);
	}
}
void dfs(int d) {
	if (d >= maxd) return;
	int next = getNext();
	if (next == 0) {
		maxd = d;
		return;
	}
	for (int j = 1; j <= sum; j++) {
		if (in[next][j])
		{
			for (int k = 1; k <= cnt; k++)//É¾µô»ð²ñ¹÷
				if (in[k][j]) Size[k]--;
			dfs(d + 1);
			for (int k = 1; k <= cnt; k++)//¸´Ô­
				if (in[k][j]) Size[k]++;
		}
	}
	return;
}
int getNext() {
	for (int i = 1; i <= cnt; i++)
		if (Size[i] == full[i]) return i;
	return 0;
}
inline int getr(int r, int c) {
	return r * (2 * n + 1) + c + 1;
}
inline int getc(int r, int c) {
	return r * (2 * n + 1) + c + n + 1;
}
inline void get_cnt() {
	int a, b, e, f;
	cnt = 0;
	for (int len = 1; len <= n; len++) {
		for (int r = 0; r + len <= n; r++) {
			for (int c = 0; c + len <= n; c++) {
				++cnt;
				full[cnt] = len * 4;
				Size[cnt] = 0;
				for (int i = 0; i < len; i++)
				{
					a = getr(r, c + i);
					b = getr(r + len, c + i);
					e = getc(r + i, c);
					f = getc(r + i, c + len);
					in[cnt][a] = true;
					in[cnt][b] = true;
					in[cnt][e] = true;
					in[cnt][f] = true;
					Size[cnt] += sticks[a] + sticks[b] + sticks[e] + sticks[f];
				}
			}
		}
	}
}
