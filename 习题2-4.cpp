//#define LOCAL
#pragma warning(disable: 4996)
#ifdef LOCAL

#endif
#include<iostream>
#include<math.h>
int main() {
	long long int n, m;
	int kase = 0;
	double sum;
	FILE *fin, *fout;
#ifdef LOCAL
	fin = freopen("œ∞Ã‚2-4in.txt", "r", stdin);
	fout = freopen("œ∞Ã‚2-4out.txt", "w", stdout);
#endif
	while (scanf("%lld %lld", &n, &m) == 2 && m && n) {
		sum = 0.0;
		while (n <= m) {
			sum += 1.0 / (double)(n*n);
			n++;
		}
		printf("Case %d: %.5lf\n", ++kase, sum);
	}
	system("pause");

}