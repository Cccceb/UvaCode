/*
���ַ��ڼ�����ʱ���Բ�ע����Ҵ�һλ������һ����λ���ó����ַ���(������ĸ����д)�������������
��
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//"\"Ҫע��
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("����in.txt", "r", stdin);
	fout = freopen("����out.txt", "w", stdout);
#endif // LOCAL

	using namespace std;
	int i;
	char c;
	while ((c=getchar())!=EOF) {
		for (i = 1; s[i] && s[i] != c; i++);//�����в���ָ��Ԫ�صļ���д��
		if (s[i]){
			putchar(s[i - 1]);
		}
		else putchar(c);//��֤�˲��ڴ�λ��Χ�ڵ��ַ�����ֱ�����
	}
}