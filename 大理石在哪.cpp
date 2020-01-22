/*
p108例5-1
*/
#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("大理石在哪in.txt", "r", stdin);
FILE *fout = freopen("大理石在哪out.txt", "w", stdout);
#endif 
using namespace std;
int main() {
	int kase = 0;
	
	int n, m;
	while (scanf("%d%d",&n,&m) == 2 && n&&m) {
		printf("CASE# %d:\n", ++kase);
		int a[10000];
		for (int i = 0; i < n; i++)  cin >> a[i];
		sort(a, a + n);
		while (m--) {
			int q; cin >> q;
			int p = lower_bound(a, a + n, q) - a;
			if (a[p] == q) printf("%d found at %d\n", q, p + 1);
			else printf("%d not found\n", q);
		}
	}
}