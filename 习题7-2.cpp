#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("习题7-2in.txt", "r", stdin);
FILE *fout = freopen("习题7-2out.txt", "w", stdout);
using namespace std;
const int maxn = 20;
void dfs(int r, int c, int dir, int step);
int dx[] = { 1,0,0,-1 };//东北南西
int dy[] = { 0,1,-1,0 };
int cnt, n;
bool g[maxn * maxn + 1][maxn * maxn + 1];
char direction[] = { 'e','n','s','w' };
int path[maxn*maxn];
bool vis[maxn*maxn + 1][maxn*maxn+ 1];
int stax, stay;
int main() {
	int T;
	scanf("%d", &T);
	int k;
	while (T--)
	{
		int x, y;
		memset(g, 1, sizeof(g));
		memset(path, 0, sizeof(path));
		
		scanf("%d\n%d", &n, &k);
		vector<int> tmpx;
		vector<int> tmpy;
		stax = stay = 120;
		cnt = 0;
		while (k--)
		{
			scanf("%d %d", &x, &y);
			g[x + stax][y + stay] = 0;
		}

		for (int i = 0; i < 4; i++) {
			memset(vis, 0, sizeof(vis));
			dfs(stax, stay, i, 1);


		}
		printf("Found %d golygon(s).\n\n", cnt);
	}
}
void dfs(int r, int c, int dir, int step) {
	path[step] = dir;
	for (int i = 0; i < step; i++) {
		r += dx[dir];
		c += dy[dir];
		if (!g[r][c] || r < 0 || c < 0 ) {
			return;
		}
	}
	if (vis[r][c]) return;
	if (step >= n) {
		if (r == (stax) && c == (stay)) {
			for (int i = 1; i <= step; i++)
				printf("%c", direction[path[i]]);
			printf("\n");
			cnt++;
		}
		return;
	}

	vis[r][c] = 1;
	if (dir == 0 || dir == 3) {
		dfs(r, c, 1, step + 1);
		dfs(r, c, 2, step + 1);
	}
	else {
		dfs(r, c, 0, step + 1);
		dfs(r, c, 3, step + 1);
	}
	vis[r][c] = 0;
}