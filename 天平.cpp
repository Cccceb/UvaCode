#include<iostream>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("天平in.txt", "r", stdin);
FILE *fout = freopen("天平out.txt", "w", stdout);
#endif 
using namespace std;
bool equ(int w) {
	int WL, DL, WR, DR;
	cin >> WL >> DL >> WR >> DR;
	bool b1 = true, b2 = true;

	if (!WL) b1 = equ(WL);
	if (!WR) b2 = equ(WR);
	w = WR + WL;
	//这一步非常重要
	return b1 && b2 && (WL*DL == WR * DR);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int w  =0;
		equ(w) ? cout << "YES" << endl : cout << "NO" << endl;
		if (T) cout << endl;

	}
}