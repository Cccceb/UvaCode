#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ÀýÌâ7-8in.txt", "r", stdin);
FILE *fout = freopen("ÀýÌâ7-8out.txt", "w", stdout);
#endif
using namespace std;
struct node {
	int v[3];
	int dist;
	bool operator < (const node &a) const {
		return dist > a.dist;
	}
};
void update_ans(node);
void solve(int, int, int, int);
const int maxn = 200 + 5;
int ans[maxn];
int vis[maxn][maxn];


int main() {
	int n, a, b, c, d;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		solve(a, b, c, d);
	}
	return 0;
}
void solve(int a, int b, int c, int d) {
	priority_queue<node> q;
	int cap[3];
	memset(ans, -1, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	cap[0] = a; cap[1] = b; cap[2] = c;
	node u;
	u.dist = 0;
	u.v[0] = 0; u.v[1] = 0; u.v[2] = c;
	q.push(u);
	vis[0][0] = 1;
	while (!q.empty())
	{
		node u = q.top(); q.pop();
		update_ans(u);
		if (ans[d] >= 0) break;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != j) {
					if (u.v[i] > 0 && u.v[j] < cap[j]) {
						int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
						node v = u;
						v.dist += amount;
						v.v[i] -= amount;
						v.v[j] += amount;
						if (!vis[v.v[0]][v.v[1]]) {
							vis[v.v[0]][v.v[1]] = 1;
							q.push(v);
						}
					}
				}
	}
	while (d >= 0)
	{
		if (ans[d] >= 0) {
			printf("%d %d\n", ans[d], d);
			return;
		}
		d--;
	}

}
void update_ans(node u) {
	for (int i = 0; i < 3; i++) {
		int d = u.v[i];
		if (ans[d] < 0 || u.dist < ans[d])
			ans[d] = u.dist;
	}
}