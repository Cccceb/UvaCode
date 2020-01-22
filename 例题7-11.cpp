#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
FILE *fin = freopen("例题7-11in.txt", "r", stdin);
FILE *fout = freopen("例题7-11out.txt", "w", stdout);
typedef long long int64;
using std::swap; using std::max;
int main() {
	int T, id = 0; scanf("%d", &T);
	while (T--) {
		int n, s1, v1, s2, v2; scanf("%d %d %d %d %d", &n, &s1, &v1, &s2, &v2);
		if (s1 > s2) swap(s1, s2), swap(v1, v2);//目的是使得S2>S1
		int64 ans = 0;
		if (n / s2 >= 65536) {	//S2>S1，如果除以S2都大于65536，说明S2就很小，那么S1更小，那么使用特殊枚举。
			for (int64 i = 0; i <= s1; i++) ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
			for (int64 i = 0; i <= s2; i++) ans = max(ans, v1 * i + (n - s1 * i) / s2 * v2);
		}
		else {//否则枚举宝物2的数量。
			for (int64 i = 0; s2 * i <= n; i++) ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
		}
		printf("Case #%d: %lld\n", ++id, ans);
	}

	return 0;
}