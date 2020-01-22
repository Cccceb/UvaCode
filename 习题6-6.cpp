#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题6-6in.txt", "r", stdin);
FILE *fout = freopen("习题6-6out.txt", "w", stdout);
#endif 
using namespace std;
int T;
string s;
int sum;
map<long long, int> base;
void dfs(int depth, int p, int e) {
	if (s[p] == '[') {
		int not_ok = 0;
		for (int i = p + 1; i != e; i++) {
			if (s[i] == '[') not_ok++;
			if (s[i] == ']') not_ok--;
			if (!not_ok&&s[i] == ',') {
				dfs(depth + 1, p + 1, i - 1);
				dfs(depth + 1, i + 1, e - 1);
			}
		}
	}
	else {
		long long w = 0;
		for (int i = p; i <= e; i++)
			w = w * 10 + s[i] - '0';
		++sum;
		++base[w << depth];//sum统计砝码总数量，base[w<<depth]统计该总重量对应的砝码个数

	}
}
int main() {
	cin >> T;
	while (T--)
	{
		cin >> s;
		sum = 0;
		base.clear();
		dfs(0, 0, s.length() - 1);
		int maxn = 0;
		for (auto it = base.begin(); it != base.end(); it++)
			maxn = max(maxn, it->second);
		cout << sum - maxn << endl;
	}
}