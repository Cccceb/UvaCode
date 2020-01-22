#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("子集生成in.txt", "r", stdin);
FILE *fout = freopen("子集生成out.txt", "w", stdout);
#endif
using namespace std;
void print_subset(int n, int *B, int cur) {
	if (cur == n) {
		for (int i = 0; i < cur; i++)
			if (B[i]) cout << i;
		cout << endl;
		return;
	}
	B[cur] = 0;
	print_subset(n, B, cur + 1);
	B[cur] = 1;
	print_subset(n, B, cur + 1);
	
}
int main() {
	int B[1000];
	int n = 10;
	print_subset(n,B,0);
}