/*
输入一个字符串，判断他是否为回文串以及镜像串。输入字符串保证不含0
*/
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
#define LOCAL
const char *s = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = { "not a palindrome","a regular palindrome"
					,"a mirrored string","a mirrored palindrome" };//要么用二维数组，
																//要么用指向数组的指针
char reverse(char c);
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("回文词in.txt", "r", stdin);
	fout = freopen("回文词out.txt", "w", stdout);
#endif // LOCAL
	using namespace std;
	char str[30];
	while ((cin >> str)) {
		int len = strlen(str); 
		int p = 1, m = 1;//p用来标识回文串，m用来标识镜像串
		//以后每个属性只有两种情况的时候考虑采用二进制
		//采用二进制表示多种状态组合时非常好用
		for (int i = 0; i < (len+1)/2; i++) {//这个+1非常重要
			if (str[i] != str[len - 1 - i]){
				p = 0;
			}
			if (reverse(str[i]) != str[len - 1 - i]) {
				m=0;
			}
		}
		printf("%s -- is %s.\n\n", str, msg[2 * m + p]);//二进制法 6666
	}
}
char reverse(char c) {
	if (isalpha(c)) return s[c - 'A'];//字母在数组中的序号
	return s[c - '0' + 25];//数字在常量数组中的序号
}