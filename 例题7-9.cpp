#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ÀýÌâ7-9in.txt", "r", stdin);
FILE *fout = freopen("ÀýÌâ7-9out.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 20;
int id[maxn][maxn];
int s[3], t[3];
char g[maxn][maxn];

int blank[maxn*maxn][5];
int dist[maxn*maxn][maxn*maxn][maxn*maxn];
int num_blank[maxn*maxn];
int r, c, w;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
inline void read_in();
inline int bfs();
inline bool isOk(int a1, int a2, int b1, int b2) {
	return a2 != b2 && !(a2 == b1 && b2 == a1);
}
inline int ID(int a, int b, int c) {
	return (a << 16) | (b << 8) | c;
}
int main() {

	while (~scanf("%d %d %d\n", &c, &r, &w) && w)
	{
		read_in();
		printf("%d\n", bfs());

	}
}
inline void read_in() {
	int x[maxn*maxn];
	int y[maxn*maxn];
	for (int i = 0; i < r; i++) fgets(g[i], 20, stdin);
	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (g[i][j] != '#') {
				x[cnt] = i;
				y[cnt] = j;
				id[i][j] = cnt;
				if (islower(g[i][j])) s[g[i][j] - 'a'] = cnt;
				else if (isupper(g[i][j])) t[g[i][j] - 'A'] = cnt;
				cnt++;
			}
		}
	for (int i = 0; i < cnt; i++) {
		num_blank[i] = 0;
		for (int k = 0; k < 5; k++) {
			int nx = x[i] + dx[k];
			int ny = y[i] + dy[k];
			if (g[nx][ny] != '#')
				blank[i][num_blank[i]++] = id[nx][ny];
		}
	}
	if (w <= 2) { num_blank[cnt] = 1; blank[cnt][0] = cnt; s[2] = t[2] = cnt++; }
	if (w <= 1) { num_blank[cnt] = 1; blank[cnt][0] = cnt; s[1] = t[1] = cnt++; }
}
inline int bfs() {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(ID(s[0], s[1], s[2]));
	dist[s[0]][s[1]][s[2]] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;
		if (a == t[0] && b == t[1] && c == t[2])
			return dist[a][b][c];

		for (int i = 0; i < num_blank[a]; i++) {
			int a2 = blank[a][i];
			for (int j = 0; j < num_blank[b]; j++) {
				int b2 = blank[b][j];
				if (!isOk(a, a2, b, b2)) continue;
				for (int k = 0; k < num_blank[c]; k++) {
					int c2 = blank[c][k];
					if (!isOk(a, a2, c, c2) || !isOk(b, b2, c, c2)) continue;

					if (dist[a2][b2][c2] == -1) {
						dist[a2][b2][c2] = dist[a][b][c] + 1;
						q.push(ID(a2, b2, c2));
					}

				}
			}
		}
	}
	return -1;
}