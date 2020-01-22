#include<iostream>
#include<string>
#include<string.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("古老的密码in.txt", "r", stdin);
FILE *fout = freopen("古老的密码out.txt", "w", stdout);
#endif 
using namespace std;
int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int main() {
	string s1, s2;
	int c1[26], c2[26];
	while (cin>>s1>>s2) {
		//cout << s1 << endl << s2 << endl;
		memset(c1, 0, 26 * sizeof(int));
		memset(c2, 0, 26 * sizeof(int));
		for (int i = 0; i < s1.length(); i++) {
			c1[s1[i] - 'A']++;
			c2[s2[i] - 'A']++;
		}
		//for (int i = 0; i < 26; i++) cout <<(char )(i+'A')<<":   "<< c1[i] << " " << c2[i] << endl;
	
			qsort(c1, 26, sizeof(int), cmp);
			qsort(c2, 26, sizeof(int), cmp);
		

		//for (int i = 0; i < 26; i++) cout<<endl << (char)(i + 'A') << ":   " << c1[i] << " " << c2[i] << endl;
		int i = 0;
		for (i = 0; i < 26; i++) {
			if (c1[i] != c2[i]) {
				cout << "NO" << endl;
				break;
			}
		}
		if (i == 26) cout << "YES" << endl;
		//if (cin.peek() == EOF) return 0;
	}
}