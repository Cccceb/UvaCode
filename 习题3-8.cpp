	#include<bits/stdc++.h>
	#pragma warning(disable:4996)
	#define LOCAL
	#ifdef LOCAL
	FILE *fin = freopen("习题3-8in.txt", "r", stdin);
	FILE *fout = freopen("习题3-8out.txt", "w", stdout);
	#endif 
	//被除数出现重复，那么出现了循环节
	const int maxn = 100000 + 5;

	int a, b;
	int vis[maxn], res[maxn];

	int main() {
		while (scanf("%d%d", &a, &b) == 2) {
			memset(vis, -1, sizeof(vis));
			int c = a % b, cnt = 0;
			c *= 10;
			while (vis[c] == -1) {
				res[cnt] = c / b;
				vis[c] = cnt++;
				c %= b;
				c *= 10;
			}
			// repeating cycle start-position
			int sta_pos = vis[c];
			printf("%d/%d = %d.", a, b, a / b);
			for (int i = 0; i < sta_pos; i++) {
				printf("%d", res[i]);
			}
			printf("(");
			if (cnt - sta_pos <= 50) {
				for (int i = sta_pos; i < cnt; i++) {
					printf("%d", res[i]);
				}
			}
			else {
				for (int i = sta_pos; i < sta_pos + 50; i++) {
					printf("%d", res[i]);
				}
				printf("...");
			}
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n\n", cnt - sta_pos);
		}
		return 0;
	}

