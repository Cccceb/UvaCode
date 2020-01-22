	#include<iostream>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ3-9in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ3-9out.txt", "w", stdout);
#endif 
using namespace std;
int main() {
	string s, t;
	while (cin >> s >> t) {
		//	cout << s <<" "<< t << endl;
		int len1 = s.length();
		int len2 = t.length();
		int flag = 1;
		int now = -1;
		for (int i = 0; i < len1; i++) {
			int j = now + 1;
			for (; j < len2; j++) {
				if (s[i] == t[j]) {
					now = j;
					break;
				}
			}
			if (j == len2) {
				flag = 0;
				break;
			}
		}
		flag ? cout << "Yes" << endl : cout << "No" << endl;
	}
}