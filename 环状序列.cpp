/*
长度位n的环状串有n种表示法；输入一个长度为n的环状DNA串(只包含A、G、C、T四种字符)的一种表示法，
你的任务时输出该环状串的最小表示(字典序最小)
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
	fin = freopen("环状序列in.txt", "r", stdin);
	fout = freopen("环状序列out.txt", "w", stdout);
#endif
	int t;
	char s[maxn]{};
	scanf_s("%d", &t);
	while (t--) {
		std::cin >> s;
		int ans = 0;//ans标识最小表示的起始位置
		//由于是环状串，所以找到起始位置即可
		for (int i = 0; i < strlen(s); i++) {
			if (less(s, i, ans)) {
				ans = i;
			}
		}
		for (int i = 0; i < strlen(s); i++) {
			putchar( s[(i + ans) % strlen(s)]);
		}
		putchar('\n');//putchar接收字符
	}
}
int less(const char* s, int p, int q) {//用const，是因为只作为输入
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[(p + i) % n] != s[(q+i)%n]){
			return s[(p+i)%n]<s[(q+i)%n];
			}
	}
	return 0;
}