/*
把手放在键盘上时，稍不注意会右错一位；输入一个错位后敲出的字符串(所有字母均大写)，输出本来想打的
字
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//"\"要注意
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("键盘in.txt", "r", stdin);
	fout = freopen("键盘out.txt", "w", stdout);
#endif // LOCAL

	using namespace std;
	int i;
	char c;
	while ((c=getchar())!=EOF) {
		for (i = 1; s[i] && s[i] != c; i++);//数组中查找指定元素的简略写法
		if (s[i]){
			putchar(s[i - 1]);
		}
		else putchar(c);//保证了不在错位范围内的字符可以直接输出
	}
}