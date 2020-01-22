
#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚3-6in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚3-6out.txt", "w", stdout);
#endif 
using namespace std;
int r, c, kase = 0, num;
void across(int r);
void down(int c);
char s[15][15];
int  x[15][15];
void show() {

	for (int i = 0; i <= r + 1; i++) {
		for (int j = 0; j <= c + 1; j++) {
			cout << s[i][j];
			if (j&&j % (c + 1) == 0) cout << endl;
		}
	}
}
int main() {
	while (scanf("%d %d", &r, &c) == 2) {
		if (kase) cout << endl;
		cout << "puzzle #" << ++kase << ":" << endl;
		getchar();
		for (int i = 0; i <= r + 1; i++)
		{
			memset(s[i], '*', c + 2);
			memset(x[i], 0, c + 2);
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				s[i][j] = getchar();
			}
			getchar();
		}

		//show();



		cout << "Across" << endl;
		num = 0;
		for (int i = 1; i <= r; i++) {
			across(i);
		}
		cout << "Down" << endl;
		num = 0;
		for (int j = 1; j <= r; j++) {
			down(j);
		}

		if (cin.peek() == '0') return 0;
	}


}
void across(int a) {
	int i = 1;
	while (i <= c) {
		string ans;
		//cout << ":::" << s[a][i] << endl;
		if (isalpha(s[a][i])) {
			if (!isalpha(s[a][i - 1]) || !isalpha(s[a - 1][i])) {
				num + 1 < 10 ? cout << "  " : cout << " ";
				cout << num + 1 << ".";
				while (isalpha(s[a][i])) {
					if (!isalpha(s[a][i - 1]) || !isalpha(s[a - 1][i])) {
						num++;
						x[a][i] = num;
					}

					ans += s[a][i];
					//cout << "ans" << i << ans << endl;
					i++;
				}
				cout << ans << endl;

			}
			else {
				i++;
			}
		}
		else	i++;

	}

}
void down(int j) {
	int i = 1;

	while (i <= c) {
		string ans;
		int b = j;

		if (isalpha(s[b][i]) == 1) {
			//cout << s[b][i] << endl;
			if (isalpha(s[b - 1][i]) != 0 || isalpha(s[b][i - 1]) != 1) {
				//cout << "≥ı º£∫ "<< s[b][i] << endl;;
				num = x[b][i];
				num < 10 ? cout << "  " : cout << " ";
				if (num) cout << num << ".";
				while (isalpha(s[b][i])) {
					//cout << "ac: " << s[b][i] << endl;
					if (!isalpha(s[b - 1][i]) || !isalpha(s[b][i - 1])) num++;
					//cout << "num: " << num << endl;
					ans += s[b][i];
					s[b][i] = 'z';
					b++;
				}
				cout << ans << endl;
				//show();
			}
		}
		i++;
	}
}