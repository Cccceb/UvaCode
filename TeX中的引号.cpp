/*
��TeX�У���˫�����ǡ�``������˫�����ǡ�''��.����һƪ��
��˫���ŵ����£���������ǰ���ת����TeX�ĸ�ʽ
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
	//�����ص��ǿ��Ա߶���д
	int c;//cҪ����Ϊ���ͣ���Ϊ�ļ������᷵��һ��������EOF������һ�����ͣ�
	int p = 1;
	while ((c = getchar())!= EOF) {//c=getchar()һ��Ҫ������������Ϊ���ںͲ�����ͬ�������Ҳ࿪ʼ
		if (c == '"') {
			printf("%s", p ? "``" : "''");
			p = !p;//�����ת�ǳ�������
		}
		else printf("%c", c);
	}
	system("pause");
}