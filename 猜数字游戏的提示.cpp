/*
实现一个经典猜数字游戏。给定答案序列和用户猜的序列，统计有多少数字位置正确(A),
有多少数字在两个序列中都出现了但位置不对(B)
*/
#include<iostream>
#include<string>
#define LOCAL
#pragma warning(disable:4996)
#define maxn 1010
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("猜数字in.txt", "r", stdin);
	fout = freopen("猜数字out.txt", "w", stdout);
#endif // LOCAL
	using namespace std;
	int n, a[maxn], b[maxn], kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++kase);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);//a存答案
		}
		while (1) {
			int A = 0, B = 0;//A存数字正确且位置正确的数字个数
							//B存数字在答案和猜测中都出现但是位置错误的个数
			for (int i = 0; i < n; i++) {
				scanf("%d", &b[i]);
				if (a[i] == b[i]) {
					A++;
				}
			}
			if (b[0] == 0) break;//在这退出死循环
			for (int d = 1; d <= 9; d++) {
				int c1 = 0, c2 = 0;//c1记录答案中数字d出现的次数，c2记录猜测中数字d出现的次数
				for (int j = 0; j < n; j++) {
					if (a[j] == d) c1++;
					if (b[j] == d) c2++;
				}
				B += c1 < c2 ? c1 : c2;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
}