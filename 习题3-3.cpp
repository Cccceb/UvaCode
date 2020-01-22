#include<iostream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题3-3in.txt", "r", stdin);
FILE *fout = freopen("习题3-3out.txt", "w", stdout);
#endif 
int main() {
	using namespace std;//要在main中定义
	int n,first=1,T;
	scanf("%d", &T);
	while (T--) {
		first = 1;
		int num[10]{};
		scanf("%d", &n);
		for (int d = 1; d <= n; d++) {
			int x = d;
			while (x > 0) {
				num[x % 10]++;
				x /= 10;
			}
		}
		for (int d = 0; d < 10; d++) {
			first == 1? first = 0: printf(" ");
			cout << num[d];
		}
		cout << endl;
	}
}