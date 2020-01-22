#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("给任务排序in.txt", "r", stdin);
FILE *fout = freopen("给任务排序out.txt", "w", stdout);
#endif 
using namespace std;
map<int, map<int, int>> g;
map<int, set<int>> Adjacency;
set<int> rudu;
const int maxn = 1000 + 5;
int topo[maxn], t, n, m;
int visit[maxn];
void dfs(int v) {

	visit[v] = 1;
	for (set<int>::iterator it = Adjacency[v].begin(); it != Adjacency[v].end(); it++) {
		if (!visit[*it]) dfs(*it);
	}
	topo[--t] = v;
}
void toposort() {
	memset(visit, 0, (n + 1) * sizeof(int));
	memset(topo, 0, (n + 1) * sizeof(int));
	t = n;
	for (int i = 1; i <= n; i++)
		if (!rudu.count(i)) {
			dfs(i);
			break;
		}
	for (int v = 1; v <= n; v++)
		if (!visit[v]) dfs(v);
}

int main() {
	while (cin >> n >> m && n&&m) {
		int x, y;
		Adjacency.clear();
		rudu.clear();
		g.clear();
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			g[x][y] = 1;
			Adjacency[x].insert(y);
			rudu.insert(y);
		}

		toposort();
		cout << topo[0];
		for (int i = 1; i < n; i++)
			cout << " " << topo[i];
		cout << endl;




	}
}