#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("�Ӽ�����in.txt", "r", stdin);
FILE *fout = freopen("�Ӽ�����out.txt", "w", stdout);
#endif
using namespace std;

void print_subset(int n, int *A, int cur) {
	//û����ʽ�ĵݹ�߽�--����޷��������Ԫ�أ���Ȼ�Ͳ����ٵݹ���
	for (int i = 0; i < cur; i++) cout << A[i];
	cout << endl;
	int s = cur ? A[cur - 1] + 1 : 0;	//������Ŀǰ�������
	for (int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
}
int main() {
	int A[1000];
	int n = 10;
	print_subset(n, A, 0);
}