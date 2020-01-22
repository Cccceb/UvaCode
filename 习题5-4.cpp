#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ5-4in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ5-4out.txt", "w", stdout);
#endif 
using namespace std;
int n;
int sa[500005]{};
int main() {
	while (cin >> n && n) {
		memset(sa, 0, 500005 * sizeof(int));
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			sa[a]++;
			sa[b]--;
		}

		bool flag = true;
		for (int i = 0; i < 500005; i++) {
			if (sa[i] != 0) {
				flag = false;
				break;
			}
		}

		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}
}