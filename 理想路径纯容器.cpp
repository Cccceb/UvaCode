#include<iostream>
#include<map>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
#define inf 0x7fffffff
int n, m;
map<int, map<int, int>> g;
int cost[100005];
set<int> visit;
int path[100005];
void bfs_end() {
	queue<int> q;
	set<int>inqueue;
	q.push(n);
	visit.clear();
	while (!q.empty()) {
		int u = q.front(); q.pop();

		visit.insert(u);
		for (map<int, int>::iterator it = g[u].begin(); it != g[u].end(); it++) {
			int v = it->first;
			if (!visit.count(v) && !inqueue.count(v)) {
				cost[v] = cost[u] + 1;
				if (v == 1) return;
				q.push(v);
				inqueue.insert(v);
			}
		}
	}
}
void bfs_start() {
	queue<int> q;
	set<int> inqueue;
	q.push(1);
	visit.clear();
	memset(path, 0, n * sizeof(int));
	while (!q.empty()) {
		int u = q.front(); q.pop();
		visit.insert(u);
		if (u == n) return;

		int minn = inf;
		map<int, set<int>> tmp;
		for (map<int, int>::iterator it = g[u].begin(); it != g[u].end(); it++) {

			int v = it->first;
			if (!visit.count(v) && cost[v] == cost[u] - 1) minn = min(minn, g[u][v]);

			tmp[g[u][v]].insert(v);
		}
		for (set<int>::iterator it = tmp[minn].begin(); it != tmp[minn].end(); it++) {
			if (!visit.count(*it) && !inqueue.count(*it) && cost[u] - 1 == cost[*it]) {
				q.push(*it);
				inqueue.insert(*it);
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
				if (g[x][y]) g[x][y] = min(g[x][y], w);
				else g[x][y] = w;
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

