/*
n(n<20)����վ��һȦ����ʱ����Ϊ1-n����������Ա��A��1��ʼ��ʱ������B��n��ʼ˳ʱ������
��ÿһ���У���ԱA��k����ͣ��������ԱB��m����ͣ����(ע���п��������˿���ͣ����ͬһ������)
����������Աѡ�е����뿪����
	����n,k,m���ÿ���ﱻѡ�е��˵ı��(����������ˣ��������Aѡ�е�)��
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("�ȼý�in.txt", "r", stdin);
FILE *fout = freopen("�ȼý�out.txt", "w", stdout);
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
int go(int p, int d, int t) {//��p����ʼ������Ϊd����t��
	while (t--) {
		do { p = (p + d + n -1) % n + 1; } while (a[p] == 0);//ע�⣡����do{}while�����������
								//ִֻ��do����䣬�����0������
	}
	return p;
}