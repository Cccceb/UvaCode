#include<iostream>
#include<iomanip>
#pragma  warning (disable:4996) 
#define LOCAL
int main() {
	using namespace std;
	FILE *fin, *fout;
	int kase = 0;
	double a, b, c;
#ifdef LOCAL
	fin = freopen("Ï°Ìâ2-5in.txt", "r", stdin);
	fout = freopen("Ï°Ìâ2-5out.txt", "w", stdout);
#endif
	while (cin >> a >> b >> c && a && c && c) {
		cout << "Case " << ++kase << ':' << setiosflags(ios::fixed) << setprecision(c) << a / b << endl;
	}
}
