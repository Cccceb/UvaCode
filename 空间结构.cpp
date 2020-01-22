#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("空间结构in.txt", "r", stdin);
FILE *fout = freopen("空间结构out.txt", "w", stdout);
#endif 
using namespace std;

vector<int> number;
vector<string> pre;
char g[64][64];
int n;
void five() {
	for (int i = 0; i < number.size(); i++) {
		int temp = 0;
		while (number[i]) {
			temp *= 10;
			temp += number[i] % 5;
			number[i] = number[i] / 5;
		}

		pre.push_back(to_string(temp) + '*');
	}
}
void draw(const string s, int &p, int r, int c, int w) {

	if (p == s.length()) return;
	char ch = s[p++];
	switch (ch - '0')
	{

	case 1:	draw(s, p, r, c, w / 2); break;
	case 2: draw(s, p, r, c + w / 2, w / 2); break;
	case 3:	draw(s, p, r + w / 2, c, w / 2); break;
	case 4:	draw(s, p, r + w / 2, c + w / 2, w / 2); break;
	default:
		break;
	}
	if (ch == '*') {
		for (int i = r; i < r + w; i++)
			for (int j = c; j < c + w; j++) {
				
					g[i][j] = '*';
				
			}
	}
}
bool judge(int r, int c, int w,char ch) {
	for (int i = r; i < r + w; i++)
		for (int j = c; j < c + w; j++)
			if (g[i][j] == ch)
				return false;
	return true;
}
void matrix(string str, int r, int c, int w) {
	
	if (judge(r, c, w,'0')) {
		pre.push_back(str);
		return;
	}
	else if (judge(r, c, w,'1')) return;
	else {
		matrix(str + "1", r, c, w / 2);
		matrix(str + "2", r, c + w / 2, w / 2);
		matrix(str + "3", r + w / 2, c, w / 2);
		matrix(str + "4", r + w / 2, c + w / 2, w / 2);
	}
}
void ten() {

	for (int i = 0; i < pre.size(); i++) {
		int temp = 0;
		for (int j = pre[i].size() - 1; j >= 0; j--)
			temp += (pre[i][j] - '0')*pow(5, j);
		number.push_back(temp);

	}
}
int main() {
	int first = 1;
	int kase = 0;
	while (cin >> n && n) {
		if (first) first = 0; else cout << endl;
		cout << "Image " << ++kase << endl;

		number.clear();
		pre.clear();
		memset(g, '.', sizeof(g));
		getchar();
		if (n > 0) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					cin >> g[i][j];
		
		
			if (judge(0, 0, n,'0')) number.push_back(0);
			else if (judge(0, 0, n,'1'));
			
			else {
				matrix("1", 0, 0, n / 2);
				matrix("2", 0, n / 2, n / 2);
				matrix("3", n / 2, 0, n / 2);
				matrix("4", n / 2, n / 2, n / 2);
				ten();
			}
			
			
			sort(number.begin(), number.end());
			if (!number.empty()) {
				for (int i = 0; i < number.size(); i++)
				{
					cout << number[i];
					if ((i + 1) % 12 == 0||i==number.size()-1) cout << endl;
					else cout << " ";
				}
			}

			cout << "Total number of black nodes = " << number.size() << endl;
			
		}
		if (n < 0) {

			string s;
			bool flag = false;
			bool zero = false;
			for (;;) {
				int a;
				
				for (int i = 0; i < 12; i++) {
					cin >> a;
					if (a == -1) {
						flag = true;
						break;
					}
					if (a == 0)zero = true;
					number.push_back(a);
				}
				if (flag) break;
			}	
			if (zero) {
				memset(g, '*', sizeof(g));
			}
			else {
				five();
				for (int i = 0; i < pre.size(); i++) {
					int p = 0;
					draw(pre[i], p, 0, 0, abs(n));
				}
			}
			


			for (int i = 0; i < abs(n); i++) {
				for (int j = 0; j < abs(n); j++)
					cout << g[i][j];
				cout << endl;
			}
		}


	}
}