#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("习题7-1in.txt", "r", stdin);
FILE *fout = freopen("习题7-1out.txt", "w", stdout);
using namespace std;
const int maxn = 20+5;
map<int, vector<int>> g;
bool bfs();
void dfs(int u,int step);
int goal, cnt,kase = 0;
bool vis[maxn];
int path[maxn];
struct edge {
	int x, y;
	edge(int x, int y) :x(x), y(y) {}
	bool operator < (const edge&a) const { return x < a.x; }
};
int main() {
	int a, b;
	while (scanf("%d", &goal) == 1) {
		g.clear();
		printf("CASE %d:\n", ++kase);
		while (scanf("%d %d", &a, &b) && a) {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 0; i < maxn; i++)
			sort(g[i].begin(), g[i].end());
		cnt = 0;
		memset(vis, 0, sizeof(0));
		if (!bfs()) {//优化，否则会T
			cnt = 0;
		}
		else {
			vis[1] = 1;
			dfs(1,0);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt,goal);
	}
}
bool bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == goal) {
			memset(vis, 0, sizeof(vis));
			return true;
		}
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (!vis[v])
			{
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	return false;
}
void dfs(int u,int step) {
	path[step] = u;
	if (u == goal) {
		printf("%d", path[0]);
		for (int i =1; i <= step; i++)
			printf(" %d", path[i]);
		printf("\n");
		cnt++;
	}
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		dfs(v,step+1);
		vis[v] = 0;
	}
}
