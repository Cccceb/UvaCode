/*
����һ���ַ������ж����Ƿ�Ϊ���Ĵ��Լ����񴮡������ַ�����֤����0
*/
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
#define LOCAL
const char *s = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = { "not a palindrome","a regular palindrome"
					,"a mirrored string","a mirrored palindrome" };//Ҫô�ö�ά���飬
																//Ҫô��ָ�������ָ��
char reverse(char c);
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("���Ĵ�in.txt", "r", stdin);
	fout = freopen("���Ĵ�out.txt", "w", stdout);
#endif // LOCAL
	using namespace std;
	char str[30];
	while ((cin >> str)) {
		int len = strlen(str); 
		int p = 1, m = 1;//p������ʶ���Ĵ���m������ʶ����
		//�Ժ�ÿ������ֻ�����������ʱ���ǲ��ö�����
		//���ö����Ʊ�ʾ����״̬���ʱ�ǳ�����
		for (int i = 0; i < (len+1)/2; i++) {//���+1�ǳ���Ҫ
			if (str[i] != str[len - 1 - i]){
				p = 0;
			}
			if (reverse(str[i]) != str[len - 1 - i]) {
				m=0;
			}
		}
		printf("%s -- is %s.\n\n", str, msg[2 * m + p]);//�����Ʒ� 6666
	}
}
char reverse(char c) {
	if (isalpha(c)) return s[c - 'A'];//��ĸ�������е����
	return s[c - '0' + 25];//�����ڳ��������е����
}