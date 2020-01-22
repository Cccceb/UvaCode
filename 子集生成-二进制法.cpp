#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("子集生成in.txt", "r", stdin);
//FILE *fout = freopen("子集生成out.txt", "w", stdout);
#endif	//LOCAL	
using namespace std;

void subset(int n, int s) {
	cout << s << " : ";
	for (int i = 0; i < n; i++)
		if (s&(1 << i)) //关键句，会考
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
