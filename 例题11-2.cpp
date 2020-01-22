#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ÀıÌâ11-2in.txt", "r", stdin);
FILE *fout = freopen("ÀıÌâ11-2out.txt", "w", stdout);
#endif 
using namespace std;
struct edge {
	int u, v, w;
	edge(int u, int v, int w) :u(u), v(v), w(w) {}
	bool operator <(const edge &a) const { return w < a.w; }
};
vector<edge> E;
int n, m;
int p[105];
int sz[105];
int find(int a) {
	return p[a] == a ? a : find(p[a]);
}
void init() {
	for (int i = 0; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}
void unite(int a, int b) {
	int pid = find(a);
	int qid = find(b);
	if (pid != qid) {
		if (sz[pid] < sz[qid]) {
			p[pid] = qid;
			sz[qid] += sz[pid];
		}
		else {
			p[qid] = pid;
			sz[pid] += sz[qid];
		}
	}
}
int main() {

	while (scanf("%d%d", &n, &m) && n) {
		E.clear();
		int u, v, w;
		int ans = INT_MAX;

		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E.push_back(edge(u, v, w));
		}

		sort(E.begin(), E.end());
		int num = 0;
		for (int i = 0; i < m; i++) {
			
			init();
			num = 0;
			for (int j = i; j < m; j++) {
				int u = E[j].u;
				int v = E[j].v;
				if (find(u) != find(v))	{
					num++;
					unite(u, v);
					if (num == n - 1)
					{
						ans = min(E[j].w-E[i].w, ans);
						break;
					}
				}
				
				
			}
		}
		printf(ans == INT_MAX ? "-1\n" : "%d\n", ans);
	}
}