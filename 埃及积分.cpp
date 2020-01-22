#include<algorithm>
#include<bits/stdc++.h>
#pragma warning (disable:4996)
FILE *fin = freopen("埃及积分in.txt", "r", stdin);
FILE *fout = freopen("埃及积分out.txt", "w", stdout);
using namespace std;
#define LL long long
inline LL get_first(LL a, LL b) { return b / a + 1; }
inline LL gcd(LL, LL);
inline bool better(int d);
bool dfs(int d, LL from, LL a, LL b);
LL maxd;
const int maxn = 1000000;
LL v[maxn], ans[maxn], a, b;
set<LL> avoid;
int main() {
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; kase++) {
		printf("Case %d: ", kase + 1);
		int k;
		scanf("%lld %lld %d", &a, &b, &k);
		LL tmp;
		avoid.clear();
		for (int i = 0; i < k; i++) {
			scanf("%lld", &tmp);
			avoid.insert(tmp);
		}
		bool ok = false;
		for (maxd = 1;; maxd++) {
			memset(ans, -1, sizeof(ans));
			if (dfs(0, get_first(a, b), a, b))
			{
				ok = true;
				break;
			}
		}
		printf("%lld/%lld=1/%lld", a, b, ans[0]);
		for (int i = 1; i <= maxd; i++) {
			printf("+1/%lld", ans[i]);
		}
		printf("\n");
	}
}
inline bool better(int d) {
	for (int i = d; i >= 0; i--) {
		if (ans[i] != v[i])
			return ans[i] == -1 || ans[i] > v[i];
	}
	return false;
}
inline LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
bool dfs(int d, LL from, LL a, LL b) {
	if (d == maxd) {
		if (b%a || avoid.count(b / a)) return false;

		v[d] = b / a;
		if (better(d)) memcpy(ans, v, sizeof(LL)*(d + 1)); //0~d
		return true;
	}
	bool ok = false;
	from = max(from, get_first(a, b));
	for (LL i = from;; i++) {
		if (b*(maxd - d + 1) <= a * i) break;
		if (avoid.count(i)) continue;
		v[d] = i;
		LL a2 = a * i - b;
		LL b2 = b * i;
		LL g = gcd(a, b);
		if (dfs(d + 1, i + 1, a2 / g, b2 / g)) ok = true;
	}
	return ok;
}