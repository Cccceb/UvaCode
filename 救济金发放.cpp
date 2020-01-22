/*
n(n<20)个人站成一圈，逆时针编号为1-n。有两个官员，A从1开始逆时针数，B从n开始顺时针数。
在每一轮中，官员A数k个就停下来，官员B数m个就停下来(注意有可能两个人可能停留在同一个人上)
接下来被官员选中的人离开队伍
	输入n,k,m输出每轮里被选中的人的编号(如果有两个人，先输出被A选中的)。
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("救济金in.txt", "r", stdin);
FILE *fout = freopen("救济金out.txt", "w", stdout);
#endif
int n, k, m, a[25];
int go(int p, int d, int t);
int main() {
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n&&k&&m) {
		int now = n;
		for (int i = 1; i <= n; i++) a[i] = i;
		int p1 = n, p2 = 1;
		while (now) {
			p1 = go(p1, +1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1); now--;
			if (p2 != p1) { printf("%3d", p2); now--; }
			a[p1] = a[p2] = 0;
			if (now) printf(",");
		}
		printf("\n");
	}
	return 0;
}
int go(int p, int d, int t) {//从p处开始，步长为d，走t步
	while (t--) {
		do { p = (p + d + n -1) % n + 1; } while (a[p] == 0);//注意！！用do{}while；正常情况下
								//只执行do的语句，如果有0才跳过
	}
	return p;
}