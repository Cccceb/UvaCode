#include<iostream>
#pragma  warning (disable:4996) 
#define LOCAL
/*
���Է���35��5��7����С��������21��3��7����С��������15��3��5����С��������
105��3��5��7����С��������������ľ�ھ�����˼������������������С�������˵�����������ͣ�
�Ժ���105���������ɵõ��𰸡�
*/
int main() {
	using namespace std;
	int a, b, c;
	FILE *fin, *fout;
	int kase = 0;
#ifdef LOCAL
	fin = freopen("ϰ��2-2in.txt", "r", stdin);
	fout = freopen("ϰ��2-2out.txt", "w", stdout);
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