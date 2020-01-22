#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题5-1in.txt", "r", stdin);
FILE *fout = freopen("习题5-1out.txt", "w", stdout);
#endif 
using namespace std;
vector<string>s[1005];
vector<string>in[1005];
void print(string &s, const int len, char extra) {
	int x = s.length();
	for (int i = 0; i < len-x; i++)
	
		s += extra;

}
int main() {
	int m = 0;//m行n列
	size_t n = 0;
	while (cin.peek() != EOF) {
		string x;
		while (cin >> x) {
			in[m].push_back(x);
			while (cin.peek() == ' ') getchar();
			if (cin.peek() == '\n') break;
			
			
			
		}
		m++;
		getchar();
	}

	for (int i = 0; i < m; i++)
	{
		s[i] = in[i];
		n = max(n, s[i].size());
	}
	
	for (int i = 0; i < m; i++) s[i].resize(n);
	


	for (int j = 0; j < n; j++) {
		int maxr = 0;
		for (int i = 0; i < m; i++) {
			
			maxr = max(maxr,(int) s[i][j].length());
		}
		for (int i = 0; i < m; i++)
			print(s[i][j], maxr, ' ');
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < in[i].size(); j++)
		{
			if (j == in[i].size() - 1) {
			 cout<<s[i][j].substr(0,s[i][j].find(" "));
			 break;
			}
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}