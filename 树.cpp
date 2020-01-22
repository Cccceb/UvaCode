#include<iostream>
#include<string>
#include<sstream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("树in.txt", "r", stdin);
FILE *fout = freopen("树out.txt", "w", stdout);
#endif 
using namespace std;
#define maxn 10000
int n = 0;
bool read(int *a) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	n = 0;
	int x;
	while (ss >> x) a[n++] = x;
	return n > 0;
}

int post_order[maxn], in_order[maxn], lch[maxn], rch[maxn];

int build(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return 0;//空树
	int root = post_order[r2];
	int p = l1;
	while (in_order[p] != root) p++;
	int cnt = p - l1;//左子树中节点个数

	lch[root] = build(l1, p - 1, l2, l2 + cnt - 1);
	rch[root] = build(p + 1, r1, l2 + cnt, r2 - 1);
	return root;
}
int best, best_sum;
void dfs(int u, int sum) {
	sum += u;
	if (!lch[u] && !rch[u]) {
		if (sum < best_sum || (best_sum == sum && u < best)) {
			best = u;
			best_sum = sum;
		}
	}

	if (lch[u]) dfs(lch[u], sum);
	if (rch[u]) dfs(rch[u], sum);

}
int main() {
	while (read(in_order)) {
		read(post_order);
		build(0, n - 1, 0, n - 1);	
		best_sum = 1e9;
		dfs(post_order[n - 1], 0);
		cout << best << endl;

	
	}
}