#include<iostream>
#pragma  warning (disable:4996) 
#define LOCAL
/*
可以发现35是5和7的最小公倍数，21是3和7的最小公倍数，15是3和5的最小公倍数，
105是3、5、7的最小公倍数。因此这四句口诀的意思就是用任意两数的最小公倍数乘第三个数并求和，
对和求105的余数即可得到答案。
*/
int main() {
	using namespace std;
	int a, b, c;
	FILE *fin, *fout;
	int kase = 0;
#ifdef LOCAL
	fin = freopen("习题2-2in.txt", "r", stdin);
	fout = freopen("习题2-2out.txt", "w", stdout);
#endif 
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		int sum;
		sum = 70 * a + 21 * b + 15 * c;
		if (sum % 105 <=100) {
			printf("Case %d: %d\n", ++kase, sum % 105);
		}
		else {
			printf("Case %d: No answer\n", ++kase);
		}
	}
	return 0;
}	