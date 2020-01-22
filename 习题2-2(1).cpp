#include<iostream>
#pragma  warning (disable:4996) 
#define LOCAL
int main() {
	using namespace std;
	int a, b, c;
	FILE *fin, *fout;
	int kase = 0;
#ifdef LOCAL
	fin = freopen("œ∞Ã‚2-2in.txt", "r", stdin);
	fout = freopen("œ∞Ã‚2-2out.txt", "w", stdout);
#endif 
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		int i;
		for (i = 10; i <= 100; i++) {
			if (i % 3 == a && i % 5 == b && i % 7 == c) {
				printf("Case %d: %d\n", ++kase, i);
				break;
			}
		}
		if (i > 100) {
			printf("No answer\n");
		}
	}
	return 0;
}