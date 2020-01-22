#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("素数环in.txt", "r", stdin);
FILE *fout = freopen("素数环out.txt", "w", stdout);
#endif 
using namespace std;
int n, vis[1000000];
int A[1000000];
int isp[100000];
int is_prime(int a) {
	for (int i = 2; i < a; i++)
		if (a%i == 0) return 0;
	return 1;
}
void dfs(int cur) {
	if (cur == n && isp[A[0] + A[n - 1]]) {
		cout << A[0];
		for (int i = 1; i < n; i++) cout <<" "<< A[i];
		cout << endl;
	}
	else {
		for (int j = 2; j <= n; j++) {
			if (!vis[j] && isp[j + A[cur - 1]]) {
				A[cur] = j;
				//回溯法
				vis[j] = 1;
				dfs(cur + 1);
				vis[j] = 0;
			}
		}
	}
}
int main() {
	int kase = 0;
	while (cin >> n) {
		if (kase) cout << endl;
		cout << "Case " << ++kase << ":" << endl;
		memset(isp, 0, 2 * n * sizeof(int));
		memset(vis, 0, 2 * n * sizeof(int));
		for (int i = 2; i <= 2 * n; i++)
			isp[i] = is_prime(i);
		isp[1] = 1;//先构造出素数表，以后方便
		A[0] = 1;//题干要求从1开始逆序输出
		dfs(1);
	
		
	}
	

}