/*
����λn�Ļ�״����n�ֱ�ʾ��������һ������Ϊn�Ļ�״DNA��(ֻ����A��G��C��T�����ַ�)��һ�ֱ�ʾ����
�������ʱ����û�״������С��ʾ(�ֵ�����С)
*/
/*
CTCC
CGAGTCAGCT
*/
/*
CCCT
AGCTCGAGTC
*/
#include<iostream>
#include<cstring>
#define maxn 105
#define LOCAL
#pragma warning(disable :4996)
int less(const char *s, int p, int q);
int main() {
#ifdef LOCAL	
	FILE *fin, *fout;
	fin = freopen("��״����in.txt", "r", stdin);
	fout = freopen("��״����out.txt", "w", stdout);
#endif
	int t;
	char s[maxn]{};
	scanf_s("%d", &t);
	while (t--) {
		std::cin >> s;
		int ans = 0;//ans��ʶ��С��ʾ����ʼλ��
		//�����ǻ�״���������ҵ���ʼλ�ü���
		for (int i = 0; i < strlen(s); i++) {
			if (less(s, i, ans)) {
				ans = i;
			}
		}
		for (int i = 0; i < strlen(s); i++) {
			putchar( s[(i + ans) % strlen(s)]);
		}
		putchar('\n');//putchar�����ַ�
	}
}
int less(const char* s, int p, int q) {//��const������Ϊֻ��Ϊ����
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[(p + i) % n] != s[(q+i)%n]){
			return s[(p+i)%n]<s[(q+i)%n];
			}
	}
	return 0;
}