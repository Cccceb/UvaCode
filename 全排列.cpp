#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("全排列in.txt", "r", stdin);
FILE *fout = freopen("全排列out.txt", "w", stdout);
#endif
using namespace std;

void dfs(int n,int *A,int cur) {
	if (cur == n) {
		for (int i = 0; i < n; i++)
			cout << A[i];
		cout << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			int ok = 1;
			for (int j = 0; j < cur; j++)
				if (A[j] == i) ok = 0;
			if (ok) {
				A[cur] = i;
				dfs(n, A, cur + 1);
			}
		}
	}
}
int main() {
	int A[1000];
	char B[1000];
	int n;
	n = 3;
	dfs(n, A, 0);
	cout << endl;
	for (int i = 0; i < n; i++) B[i] = 'a'+i;
	sort(B, B + n);
	do {
		for (int i = 0; i < n; i++) cout << B[i];
		cout << endl;
	} while (next_permutation(B, B + n));
}