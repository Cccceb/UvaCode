/*
编写一个解码程序。首先输入一个编码头，将每个串依次对应编码头中的每个字符。
接下来的编码文本，编码文本由多个小节组成，每个小节的前三个数字代表小节中每个编码的长度，
然后是各个字符的编码，以全1结束。编码文本以编码长度全0结束
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("信息解码in.txt", "r", stdin);
FILE *fout = freopen("信息解码out.txt", "w", stdout);
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
	while (c--) v = 2 * v + readchar() - '0';//读取二进制数，并转化为十进制
	return v;
}
int readcodes() {
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();//读取一个不为换行的字符
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