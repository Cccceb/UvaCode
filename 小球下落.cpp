#include<iostream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("小球下落in.txt", "r", stdin);
FILE *fout = freopen("小球下落out.txt", "w", stdout);
#endif 
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int num, depth;
		cin >> depth >> num;
		int No = 1;
		for (int i = 0; i < depth-1; i++) {
			if (num % 2 == 1) {
				No = 2 * No;
				num = (num + 1) / 2;
			}
			else {
				No = 2 * No + 1;
				num = num / 2;
			}
		}


		cout << No << endl;
	}
}