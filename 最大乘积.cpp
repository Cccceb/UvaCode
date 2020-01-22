#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("最大乘积in.txt", "r", stdin);
FILE *fout = freopen("最大乘积out.txt", "w", stdout);
#endif 
using namespace std;
vector<int> list1;
int main() {
	int n;
	int kase = 0;
	while (cin >> n) {
		list1.clear();
		for (int i = 0; i < n; i++) {
			int a = 0;
			cin >> a;
			list1.push_back(a);
		}
		getchar();
		long long mulmax = 0;
		for (int u = 0; u < n; u++) {

			for (int v = n - 1; v >= u; v--) {
				long long mul = 1;
				for (int i = u; i <= v; i++) {
					mul *= list1[i];
				}
				if (mul >0 ) mulmax = max(mul, mulmax);
				
			}
		}
		cout << "Case #" << ++kase << ": The maximum product is " << mulmax << "." << endl << endl;;
	}


}