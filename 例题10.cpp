#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����10in.txt", "r", stdin);
FILE *fout = freopen("����10out.txt", "w", stdout);
#endif
using namespace std; 
int f(int i) {
	return i == 1 ? 1 : f(i / 2) + 1;
}
int main() {
	int n;
	while (cin >> n) {
		cout << f(n) << endl;
	}
}