#include<cstdio>
#include<cstring>
//#include<vector>
//#include<queue>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("战场in.txt", "r", stdin);
FILE *fout = freopen("战场out.txt", "w", stdout);
#endif 
using namespace std;

const int maxn = 1000 + 1;
const double W = 1000;

int x[maxn], y[maxn], r[maxn];
int n;
double left, right;

bool intersect(int a, int b) {
	return sqrt((x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b])) < r[a] + r[b];
}
void check(int u)
{
	if (x[u] < r[u]) left = min(left, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
	if (x[u] + r[u] > W) right = min(right, y[u] - sqrt(r[u] * r[u] - (W - x[u])*(W - x[u])));
}
int vis[maxn];
//top to bottom
bool dfs(int u)
{
	if (vis[u]) return false;
	vis[u] = 1;
	if (y[u] < r[u]) return true;
	for (int v = 0; v < n; v++) {
		if (intersect(u, v) && dfs(v)) return true;
	}
	check(u);
	return false;
}


int main()
{
#ifdef local
	freopen("in.txt", "r", stdin);
#endif // local
	while (~scanf("%d", &n)) {
		bool ok = true;
		memset(vis, 0, sizeof(vis));
		left = right = W;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", x + i, y + i, r + i);
		}
		for (int i = 0; i < n; i++) {
			if (r[i] + y[i] >= W && dfs(i)) { ok = false; break; }
		}
		if (ok) printf("0.00 %.2lf 1000.00 %.2lf\n", left, right);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
