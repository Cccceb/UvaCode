/*
在TeX中，左双引号是“``”，有双引号是“''”.输入一篇包
含双引号的文章，你的任务是把它转换乘TeX的格式
*/
#include<iostream>
#include<cstring>
#pragma warning(disable :4996)
//#define LOCAL
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("Texin.txt", "r", stdin);
	fout = freopen("Texout.txt", "w", stdout);
#endif // LOCAL
	//本题特点是可以边读边写
	int c;//c要定义为整型，因为文件结束会返回一个特殊标记EOF，它是一个整型；
	int p = 1;
	while ((c = getchar())!= EOF) {//c=getchar()一定要先括起来，因为等于和不等于同级，从右侧开始
		if (c == '"') {
			printf("%s", p ? "``" : "''");
			p = !p;//这个反转非常的灵性
		}
		else printf("%c", c);
	}
	system("pause");
}