/*
�ҳ���������abc*de(��λ��������λ��)����ʽ��ʹ������������ʽ�У��������ֶ�����һ���ض��õ�����
���ϡ��������ּ���(��������֮��û�пո�)�����������ʽ��ÿ����ʽǰӦ�б�ţ�֮��Ӧ��һ�����С�
���������������

*/
#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
int main() {
	using namespace std;
	FILE *fin, *fout;
	fin = freopen("��ʽ����in.txt", "r", stdin);
	fout = freopen("��ʽ����out.txt", "w", stdout);
	int abc, de;
	int count = 0;
	char s[20], buf[99];
	scanf("%s", s);
	for (abc = 111; abc <= 999; abc++) {
		for (de = 11; de <= 99; de++) {
			int x = abc * (de % 10);//�˸�λ
			int y = abc * (de / 10);//��ʮλ
			int z = abc * de;//x+y=z
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);//���뵽ָ���ַ���
			int ok = 1;
			for (int i = 0; i < strlen(buf); i++) {
				if (strchr(s, buf[i]) == NULL) {//����ָ���ַ������Ƿ�����ַ�
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