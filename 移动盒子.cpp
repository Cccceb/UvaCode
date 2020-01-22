#include<iostream>
#include<cstring>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("移动盒子in.txt", "r", stdin);
FILE *fout = freopen("移动盒子out.txt", "w", stdout);
#endif 
#define maxn 100005
int le[maxn], ri[maxn];
void link(int l, int r) {
	le[r] = l;
	ri[l] = r;
}
int main() {
	int n, m;
	int kase = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) {
			le[i] = i - 1;
			ri[i] = (i + 1) % (n + 1);
		}
		ri[0] = 1;
		le[0] = n;
		int op, x, y, inv = 0;

		while (m--) {


			scanf("%d", &op);
			if (op == 4) inv = !inv;
			else {
				scanf("%d%d", &x, &y);
				if (op == 3 && ri[y] == x) std::swap(x, y);
				if (op != 3 && inv) op = 3 - op;
				if (op == 1 && x == le[y]) continue;
				if (op == 2 && x == ri[y]) continue;

				int lx = le[x], rx = ri[x], ly = le[y], ry = ri[y];
				if (op == 1) {
					link(lx, rx); link(ly, x); link(x, y);
				}
				else if (op == 2) {
					link(lx, rx); link(y, x); link(x, ry);
				}
				/*else if (op == 3) {
					if (right[y] == x) {
						link(y, rx); link(ly, x); link(x, y);
					}
					else if (left[y] == x) {
						link(lx, y); link(y, x); link(x, ry);
					}
					else {
						link(ly, x); link(x, ry);
						link(lx, y); link(y, rx);
					}

				}*/
				else if (op == 3) {
					if (ri[x] == y) {
						link(lx, y); link(y, x); link(x, ry);
					}
					else { link(lx, y); link(y, rx); link(ly, x); link(x, ry); }
				}
			}
		}
		int b = 0;
		
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			b = ri[b];
			//std::cout << i<<": "<<right[b] << std::endl;
			if (i % 2 == 1) ans += b;
		}
		/*using namespace std;
		cout << endl;*/
		if (inv && n % 2 == 0) ans = (long long)n*(n + 1) / 2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);

	}



}