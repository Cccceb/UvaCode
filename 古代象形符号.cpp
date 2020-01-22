#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("古代象形符号in.txt", "r", stdin);
FILE *fout = freopen("古代象形符号out.txt", "w", stdout);
#endif 
using namespace std;
vector<string> g;
int vis[205][205];
string b[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011" ,"1100","1101","1110","1111" };
char c[] = { 'W','A','K','J','S','D' };
struct Node {
	int x, y;
	Node(int x, int y) :x(x), y(y) {}
};
int H, W, cnt, num;
bool notOk(int a, int b) {
	return vis[a][b] || a < 0 || a >= g.size() || b < 0 || b >= g[a].size();
}
void dfs(Node u, char c) {
	vis[u.x][u.y] = 1;
	for (int i = 0; i < 4; i++) {
		int a = u.x + dx[i];
		int b = u.y + dy[i];
		if (notOk(a, b)) continue;
		if (c == '1'&& g[a][b] == '0') {

			cnt++;
			dfs(Node(a, b), '0');
		}
		if (g[a][b] == c) dfs(Node(a, b), c);
	}
}

int main() {
	int kase = 0;
	while (cin >> H >> W && H) {

		getchar();
		memset(vis, 0, sizeof(vis));
		g.clear();
		g.resize(H + 2);
		g.front() = string(W * 4 + 2, '0');//加一层白边
		for (int i = 1; i <= H; ++i) {//读取输入
			g[i] = "0";//加一层白边
			string s;
			getline(cin, s);
			for (char c : s)
			{
				if (isdigit(c)) g[i] += b[c - '0'];
				else g[i] += b[c - 'a' + 10];
			}
			g[i] += "0";//加一层白边
		}
		g.back() = string(W * 4 + 2, '0');//加一层白边


		dfs(Node(0, 0), '0');

		string ans;
		for (int i = 1; i < g.size(); i++) {
			for (int j = 1; j < g[i].size(); j++) {
				if (!vis[i][j] && g[i][j] == '1') {
					cnt = 0;
					dfs(Node(i, j), '1');
					ans += c[cnt];

				}


			}
		}

		cout << "Case " << ++kase << ": ";

		sort(ans.begin(), ans.end());

		cout << ans << endl;

	}

}