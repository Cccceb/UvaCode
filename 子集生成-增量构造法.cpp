#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("子集生成in.txt", "r", stdin);
FILE *fout = freopen("子集生成out.txt", "w", stdout);
#endif
using namespace std;

void print_subset(int n, int *A, int cur) {
	//没有显式的递归边界--如果无法继续添加元素，自然就不会再递归了
	for (int i = 0; i < cur; i++) cout << A[i];
	cout << endl;
	int s = cur ? A[cur - 1] + 1 : 0;	//！！！目前还不理解
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