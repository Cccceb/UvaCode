#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("�Ӽ�����in.txt", "r", stdin);
//FILE *fout = freopen("�Ӽ�����out.txt", "w", stdout);
#endif	//LOCAL	
using namespace std;

void subset(int n, int s) {
	cout << s << " : ";
	for (int i = 0; i < n; i++)
		if (s&(1 << i)) //�ؼ��䣬�ῼ
			cout << i;
	cout << endl;
}
void print_subset(int n) {
	for (int i = 0; i < (1 << n); i++)
		subset(n, i);
}
int main() {
	int n = 10;
	print_subset(n);
	system("pause");
}
