/*
��дһ�����������������һ������ͷ����ÿ�������ζ�Ӧ����ͷ�е�ÿ���ַ���
�������ı����ı��������ı��ɶ��С����ɣ�ÿ��С�ڵ�ǰ�������ִ���С����ÿ������ĳ��ȣ�
Ȼ���Ǹ����ַ��ı��룬��ȫ1�����������ı��Ա��볤��ȫ0����
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("��Ϣ����in.txt", "r", stdin);
FILE *fout = freopen("��Ϣ����out.txt", "w", stdout);
#endif 
int code[8][1 << 8];
int readcodes();
int readint(int);
int readchar();
int main() {
	while (readcodes()) {
		for (;;) {
			int len = readint(3);
			if (len == 0) break;
			for (;;) {
				int v = readint(len);
				if (v == (1<<len ) - 1)break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}
int readchar() {
	for (;;) {
		int ch = getchar();
		if (ch != '\n'&&ch != '\r') return ch;
	}
}
int readint(int c) {
	int v = 0;
	while (c--) v = 2 * v + readchar() - '0';//��ȡ������������ת��Ϊʮ����
	return v;
}
int readcodes() {
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();//��ȡһ����Ϊ���е��ַ�
	for (int len = 2; len <= 7; len++) {
		for (int i = 0; i < (1<<len) - 1; i++) {
			int ch = getchar();
			if (ch == EOF) return 0;
			if (ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		}
	}
	return 1;
}