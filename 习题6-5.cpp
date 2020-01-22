#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题6-5in.txt", "r", stdin);
FILE *fout = freopen("习题6-5out.txt", "w", stdout);
#endif 
using namespace std;
int n, x, y, k;
int g[20][20];
struct node {
	int r, c, k, step;

	node(int r, int c, int k, int step = 0) :r(r), c(c), k(k), step(step) {}
};
int step[20][20];
int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
int min_step;
void bfs() {
	queue<node>q;
	q.push(node(0, 0, k));
	int block = 0;
	while (!q.empty()) {
		node u = q.front(); q.pop();

		if (u.r == x - 1 && u.c == y - 1) {
			min_step = u.step;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int r = u.r + dr[i], c = u.c + dc[i];
			if (r >= 0 && r < x&&c >= 0 && c < y) {
				if (step[r][c] < u.k) {//u.k是走到step[r][c]处，还剩余的跳过障碍的机会，所以要保留大的
					step[r][c] = u.k;
				}
				else continue;//如果step[r][c]更大，说明目前正在走的路不是最好的(因为bfs走到每个节点的步数是一定的
							  //所以剩余的跨越障碍的次数越多越好),不需要再走下去，所以不入队)
				if (g[r][c] == 0) q.push(node(r, c, k, u.step + 1));
				else if(u.k) q.push(node(r, c, u.k - 1, u.step + 1));
			}
		}
	}
}
int main() {
	cin >> n;
	while (n--) {

		memset(g, 0, sizeof(g));
		memset(step, -1, sizeof(step));
		cin >> x >> y;
		cin >> k;
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				cin >> g[i][j];
		min_step = 999;
		bfs();
		min_step == 999 ? cout << "-1" << endl:cout << min_step << endl;
	}
}