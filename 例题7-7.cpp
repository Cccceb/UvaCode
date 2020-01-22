#include <cstdio>
#include <cfloat>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
FILE *fin = freopen("ÀýÌâ7-7in.txt", "r", stdin);
FILE *fout = freopen("ÀýÌâ7-7out.txt", "w", stdout);
const int maxn = 7;
int vis[1 << maxn];
int tree[1 << maxn];
int w[1 << maxn];
int val[1 << maxn];
int n, s;
double r, left, right, ans;

void findedge(double mid, int cur) {
	int a = cur * 2;
	int b = cur * 2 + 1;
	double nl = mid - ((double)val[b] / (val[a] + val[b]));
	double nr = mid + ((double)val[a] / (val[a] + val[b]));

	left = min(left, nl);
	right = max(right, nr);

	if (tree[cur] < 0) {
		findedge(nl, a);
		findedge(nr, b);
	}

}
void update_ans(int num) {
	memset(val, 0, sizeof(val));
	for (int i = num; i >= 1; i--) {
		if (tree[i] < 0) val[i] = val[i * 2] + val[i * 2 + 1];
		else if(tree[i]>0) val[i] = w[tree[i]];
	}
	left = DBL_MAX;
	right = DBL_MIN;

	findedge(double(0), 1);
	double fin = right - left;
	if (fin < r) {
		ans = max(ans, fin);
	}

}
void dfs(int step, int leaf, int node) {
	if (!node && !leaf) {
		update_ans(step - 1);
		return;
	}
	if ((!node&&leaf) || (node && !leaf)) {
		return;
	}
	if (tree[step / 2] != -1) {
		dfs(step + 1, leaf, node);
		return;
	}
	if (leaf < node) {
		tree[step] = -1;
		dfs(step + 1, leaf + 1, node);
		tree[step] = 0;
	}
	for (int i = 1; i <= s; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			tree[step] = i;

			dfs(step + 1, leaf - 1, node - 1);

			vis[i] = 0;
			tree[step] = 0;
		}
	}

}
int main() {

	scanf("%d", &n);

	while (n--) {
		ans = -1;
		memset(vis, 0, sizeof(vis));

		scanf("%lf %d", &r, &s);
		for (int i = 1; i <= s; i++) {
			scanf("%d", &w[i]);
		}
		if (s == 1) {
			printf("%.16f\n", double(0));
			continue;
		}
		
		tree[1] = -1;
		dfs(2, 2, s);

		if (ans == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%.16lf\n", ans);
		}
	}
	
}