#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<queue>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("战场in.txt", "r", stdin);
FILE *fout = freopen("战场out.txt", "w", stdout);
#endif 
using namespace std;
int vis[1005];
int n;
double le, ri;
struct Node {
	double x, y, r;
	Node(double x, double y, double r) :x(x), y(y), r(r) {}
};
vector<Node> enemy;
bool intersect(int u, int v) {
	return sqrt(pow(enemy[u].x - enemy[v].x, 2) + pow(enemy[u].y - enemy[v].y, 2)) < enemy[u].r + enemy[v].r;
}

void check_circle(int u) {
	if (enemy[u].x - enemy[u].r < 0)
		le = min(le, enemy[u].y - sqrt(enemy[u].r * enemy[u].r - enemy[u].x * enemy[u].x));
	if (enemy[u].x + enemy[u].r > 1000)
		ri = min(ri, enemy[u].y - sqrt(enemy[u].r * enemy[u].r - (1000 - enemy[u].x) *(1000 - enemy[u].x)));
}

bool bfs(int i) {
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (enemy[u].y - enemy[u].r <= 0) {
			return false;
		}
		vis[u] = 1;
		check_circle(u);
		for (int i = 0; i < n; i++)
		{
			if (!vis[i] && intersect(i, u))
				q.push(i);
		}
	}
	return true;
}
int main() {

	while (cin >> n) {
		memset(vis, 0, sizeof(vis));
		enemy.clear();
		le = ri = 1000;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			enemy.push_back(Node(x, y, r));
		}

		bool flag = true;
		for (int i = 0; i < n; i++)
			if (enemy[i].y + enemy[i].r >= 1000)
				flag = bfs(i);

		if (!flag) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		printf("0.00 %.2f 1000.00 %.2f\n",le, ri);


	}

}