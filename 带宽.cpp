#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("던욱in.txt", "r", stdin);
FILE *fout = freopen("던욱out.txt", "w", stdout);
#endif 
using namespace std;
map<int, set<int>> xl;
int n;
int A[10],ans[10];
int vis[26];
int minb = 100000000;
void dfs(int cur, int B) {
	if (cur == n)
	{
		memcpy(ans, A, sizeof(int)*n);
		minb = B;
	}
	else for (auto it = xl.begin(); it != xl.end();it++) {
		int i = it->first;
		if (!vis[i]) {
			int m = 0;
			for (int j = 0; j < cur; j++)
				if (!vis[A[j]] && xl[i].count(A[j])) 
					m++;
			if (m >= minb) return;

			int ok = 1;
			A[cur] = i;
			for (int j = 0; j < cur; j++) {
				
				if (xl[i].count(A[j])) {
					int w = cur - j;
					if (w > B) B = w;
					if (B >= minb) return;

					
				}
					
			}

			if (ok) {
				vis[i] = 1;
				dfs(cur + 1, B);
				vis[i] = 0;
			}
		}
	}
}
int main() {
	string line;
	while (getline(cin, line) && line != "#") {
		xl.clear();
		memset(A, -1, sizeof(A));
		bool flag = true;
		char u;
		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i])) {
				if (flag) {
					u = line[i] - 'A';
					flag = false;
					xl[line[i] - 'A'];
				}
				else {
					xl[u].insert(line[i] - 'A');
					xl[line[i] - 'A'].insert(u);
				}
			}
			else if (line[i] == ';') flag = true;
		}
		n = xl.size();
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		minb = 100000000;
		dfs(0, 0);
		for (int i = 0; i < n; i++) cout << char('A' + ans[i]) << " ";
		cout << "-> "<<minb << endl;


	}
}