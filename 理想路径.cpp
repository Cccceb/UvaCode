#include<iostream>
#include<map>
#include<string.h>
#include<queue>
#include<set>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("理想路径in.txt", "r", stdin);
FILE *fout = freopen("理想路径out.txt", "w", stdout);
#endif 
using namespace std;
#define inf 0x7fffffff
int n, m;
map<int, map<int, int>> g;
int cost[100005];
bool visit[100005];
int path[100005];

void bfs_end() {
	queue<int> q;

	q.push(n);
	memset(visit, false, (n + 1) * sizeof(bool));
	while (!q.empty()) {
		int u = q.front(); q.pop();

		visit[u] = true;
		for (map<int, int>::iterator it = g[u].begin(); it != g[u].end(); it++) {
			int v = it->first;
			if (!visit[v] ) {
				cost[v] = cost[u] + 1;
				if (v == 1) return;
				q.push(v);
				visit[v] = true;
			}
		}
	}
}
void bfs_start() {
	queue<int> q;

	q.push(1);
	memset(visit, false, (n + 1) * sizeof(bool));
	memset(path, 0, (n + 1) * sizeof(int));
	while (!q.empty()) {
		int u = q.front(); q.pop();
		visit[u] = true;
		if (u == n) return;

		int minn = inf;
		map<int, set<int>> tmp;
		for (map<int, int>::iterator it = g[u].begin(); it != g[u].end(); it++) {

			int v = it->first;
			if (cost[v] == cost[u] - 1) 
				minn = min(minn, g[u][v]);

			tmp[g[u][v]].insert(v);
		}
		for (set<int>::iterator it = tmp[minn].begin(); it != tmp[minn].end(); it++) {
			if (!visit[*it] &&  cost[u] - 1 == cost[*it]) {
				q.push(*it);
				visit[*it] = true;
			}

		}
		int index = cost[1] - cost[u];
		if (path[index] == 0) path[index] = minn;
		else path[index] = min(path[index], minn);


	}
}
int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		memset(cost, -1, n * sizeof(int));
		cost[n] = 0;
		g.clear();
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			if (x != y) {
				g[x][y] = g[x][y] ? min(g[x][y], w) : w;
				g[y][x] = g[x][y];
			}

		}


		bfs_end();


		bfs_start();


		cout << cost[1] << endl << path[0];
		for (int i = 1; i < cost[1]; i++) cout << " " << path[i];
		cout << endl;

	}
}

