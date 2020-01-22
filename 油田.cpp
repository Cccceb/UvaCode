#include<iostream>
#include<string>
#include<vector>
#include<map>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ÓÍÌïin.txt", "r", stdin);
FILE *fout = freopen("ÓÍÌïout.txt", "w", stdout);
#endif 
using namespace std;
vector<string> idx;
int num, m, n;;
map<int, map<int, int>>have_travel;
void dfs(int r, int c) {

	if (r < 0 || c < 0 || r >= m || c >= n) return;
	if (have_travel[r][c] || idx[r][c] != '@') return;
	idx[r][c] = num;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i||j) dfs(r + i, c + j);
		}
	}
}
int main() {
	string s;
	while (cin >> m >> n&&m&&n) {

		getchar();
		idx.clear();
		have_travel.clear();
		num = 1;
		for (int i = 0; i < m; i++) {
			getline(cin, s);
			idx.push_back(s);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!have_travel[i][j] && idx[i][j] == '@') {
					dfs(i, j);
					num++;
				}
			}
		}
		cout << num - 1 << endl;
	}

}