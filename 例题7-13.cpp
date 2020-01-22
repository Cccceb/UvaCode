#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("例题7-13in.txt", "r", stdin);
FILE *fout = freopen("例题7-13out.txt", "w", stdout);
int res[50];
int maxd;
bool dfs(int d, int maxn);
int n;
int main() {
	while (scanf("%d", &n) && n) {
		for (maxd = 0;; maxd++)
			if (dfs(0, 1)) break;
		printf("%d\n", maxd);
	}
}
bool dfs(int d, int maxn) {//当前的步数d，当前的最大值maxn
	if (d == maxd)
		if (maxn == n || maxn << (maxd - d) == n) return true;
	if (maxn <= 0 || maxn << (maxd - d) < n) return false;
	res[d] = maxn;
	for (int i = 0; i <= d; i++) {
		if (dfs(d + 1, maxn + res[i])) return true;
		if (dfs(d + 1, maxn - res[i])) return true;
	}
	return false;
}