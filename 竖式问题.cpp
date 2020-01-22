/*
找出所有形如abc*de(三位数乘以两位数)的算式，使得在完整的竖式中，所有数字都属于一个特定得到数字
集合。输入数字集合(相邻数字之间没有空格)，输出所有竖式。每个竖式前应有编号，之后应有一个空行。
最后输出解的总数。

*/
#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
int main() {
	using namespace std;
	FILE *fin, *fout;
	fin = freopen("竖式问题in.txt", "r", stdin);
	fout = freopen("竖式问题out.txt", "w", stdout);
	int abc, de;
	int count = 0;
	char s[20], buf[99];
	scanf("%s", s);
	for (abc = 111; abc <= 999; abc++) {
		for (de = 11; de <= 99; de++) {
			int x = abc * (de % 10);//乘个位
			int y = abc * (de / 10);//乘十位
			int z = abc * de;//x+y=z
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);//输入到指定字符串
			int ok = 1;
			for (int i = 0; i < strlen(buf); i++) {
				if (strchr(s, buf[i]) == NULL) {//查找指定字符串中是否包含字符
					ok = 0;
					break;
				}
			}
				if (ok == 1) {
					cout << "<" << ++count << ">" << endl;
					printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
				}
		}
	}
	cout << "The number of solutions = " << count << endl;
	system("pause");
}