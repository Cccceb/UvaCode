/*
ʵ��һ�������������Ϸ�����������к��û��µ����У�ͳ���ж�������λ����ȷ(A),
�ж������������������ж������˵�λ�ò���(B)
*/
#include<iostream>
#include<string>
#define LOCAL
#pragma warning(disable:4996)
#define maxn 1010
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("������in.txt", "r", stdin);
	fout = freopen("������out.txt", "w", stdout);
#endif // LOCAL
	using namespace std;
	int n, a[maxn], b[maxn], kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		printf("Game %d:\n", ++kase);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);//a���
		}
		while (1) {
			int A = 0, B = 0;//A��������ȷ��λ����ȷ�����ָ���
							//B�������ڴ𰸺Ͳ²��ж����ֵ���λ�ô���ĸ���
			for (int i = 0; i < n; i++) {
				scanf("%d", &b[i]);
				if (a[i] == b[i]) {
					A++;
				}
			}
			if (b[0] == 0) break;//�����˳���ѭ��
			for (int d = 1; d <= 9; d++) {
				int c1 = 0, c2 = 0;//c1��¼��������d���ֵĴ�����c2��¼�²�������d���ֵĴ���
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