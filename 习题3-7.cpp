#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ3-7in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ3-7out.txt", "w", stdout);
#endif 
using namespace std;
int s[4];
char jz[55][1005]{};
char c[4] = { 'A','C','G','T' };
int hamm[1005]{};
char ans[1005];
int T, m, n, x;
void add(char i);
int hamming();
int main() {

	cin >> T;
	while (T--) {
		x = 0;
		scanf("%d%d", &m, &n);
		getchar();
		memset(hamm, 0, 1005 * sizeof(int));
		memset(ans, 0, 1005 * sizeof(char));
		for (int i = 0; i < 55; i++)
			memset(jz[i], 0, 1005 * sizeof(char));
		int i;
		for (int k = 0; k < m; k++) {
			for (int j = 0; j < n; j++) {
				jz[k][j] = getchar();
			}
			getchar();
		}
		for (i = 0; i < n; i++) {
			memset(s, 0, 4 * sizeof(int));
			for (int j = 0; j < m; j++) {
				add(jz[j][i]);
			}
			int max = s[0];
			int y = 0;
			for (int k = 0; k < 4; k++) {
				if (s[k] > max) {
					max = s[k];
					y = k;
				}
			}
			ans[x] = c[y];
			x++;
		}
		ans[x] = '\0';
		cout << ans << endl;
		cout << hamming() << endl;
	}
}

int hamming() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i] != jz[j][i]) {
				sum++;
			}
		}
	}
	return sum;
}
void add(char i) {
	switch (i) {
	case 'A':s[0]++; break;
	case 'C':s[1]++; break;
	case 'G':s[2]++; break;
	case 'T':s[3]++; break;
	default:;
	}
}