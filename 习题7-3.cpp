#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("œ∞Ã‚7-3in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚7-3out.txt", "w", stdout);
using namespace std;
const int maxr = 7;
const int maxc = 8;
int tot;
int id[maxr][maxc];
int ans[maxr][maxc];
int vis[maxr][maxc];
int in[maxr][maxc];
int cnt;
int used[29];
const int dx[] = { 1,0 };
const int dy[] = { 0,1 };
void dfs(int x, int y, int step);
void dfs(int x, int y);
int main() {
	int kase = 0;
	for (int i = 0; i < 7; i++)
		for (int j = i; j < 7; j++)
		{
			id[i][j] = ++cnt;
		}
	while (1) {

		tot = 0;
		memset(vis, 0, sizeof(vis));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < maxr; i++) {
			for (int j = 0; j < maxc; j++) {
				if (scanf("%d", &in[i][j]) != 1)
					return 0;
			}
			scanf("\n");
		}
		if (kase) printf("\n\n\n\n\n");
		printf("Layout #%d:\n\n\n", ++kase);
		for (int i = 0; i < maxr; i++) {
			for (int j = 0; j < maxc; j++) {
				printf("   %d", in[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		printf("Maps resulting from layout #%d are:\n\n\n", kase);
		dfs(0, 0, 0);
		printf("There are %d solution(s) for layout #%d.\n", tot, kase);
	}

}

void dfs(int x, int y, int step) {

	int newx, newy, now;
	if (step == cnt) {
		for (int i = 0; i < maxr; i++) {
			for (int j = 0; j < maxc; j++)
				printf(ans[i][j] < 10 ? "   %d" : "  %d", ans[i][j]);
			printf("\n");
		}
		tot++;
		printf("\n\n");
		return;
	}

	if (y == maxc) { x++; y = 0; }
	if (vis[x][y]) dfs(x, y + 1, step);
	else {
		for (int i = 0; i < 2; i++)
		{
			newx = x + dx[i];
			newy = y + dy[i];

			if (newx < 0 || newy < 0 || newx >= maxr || newy >= maxc || vis[newx][newy])
				continue;
			now = max(id[in[x][y]][in[newx][newy]], id[in[newx][newy]][in[x][y]]);
			if (now)
			{
				if (used[now]) continue;

				ans[x][y] = ans[newx][newy] = now;
				vis[newx][newy] = 1;
				used[now] = 1;

				dfs(x, y + 1, step + 1);

				ans[x][y] = ans[newx][newy] = 0;
				vis[x][y] = vis[newx][newy] = 0;
				used[now] = 0;
			}
		}
	}
}