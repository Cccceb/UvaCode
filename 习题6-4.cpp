#include<iostream>
#include<iostream>
#include<queue>
#include<string>
#include<map>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚6-4in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚6-4out.txt", "w", stdout);
#endif 
using namespace std;
struct node {
	int r, c;
	node() :r(-1), c(-1) {}
	node(int r, int c) :r(r), c(c) {}
	bool operator <	 (const node &a) const { return r < a.r || r == a.r&&c < a.c; }
	bool operator == (const node &a) const { return r == a.r&&c == a.c; }

};
node move(node u, int i) {
	int r = u.r;
	int c = u.c;
	switch (i)
	{
	case 0:return node(r + 2, c - 1); break;
	case 1:return node(r + 1, c - 2); break;
	case 2:return node(r - 1, c - 2); break;
	case 3:return node(r - 2, c - 1); break;
	case 4:return node(r - 2, c + 1); break;
	case 5:return node(r - 1, c + 2); break;
	case 6:return node(r + 1, c + 2); break;
	case 7:return node(r + 2, c + 1); break;
	default:
		return node(-1, -1);
		break;
	}
}
int visit[8][8];
int le;
bool legal(int i) { return i >= 0 && i < 8; }
map<node, node> path;
void bfs(node start, node end) {
	queue<node> q;
	q.push(start);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		if (u == end) break;

		for (int i = 0; i < 8; i++) {
			node v = move(u, i);
			int r = v.r, c = v.c;
			if (legal(r) && legal(c) && !visit[r][c]) {
				q.push(v);
				visit[r][c] = 1;
				path[v] = u;
			}
		}


	}
}
int main() {
	string a, b;
	while (cin >> a >> b) {
		memset(visit, 0, sizeof(visit));
		path.clear();
		le = 0;
		node start_point = node(a[0] - 'a', 8 - (a[1] - '0'));
		node end_point = node(b[0] - 'a', 8 - (b[1] - '0'));
		bfs(start_point, end_point);
		node u = end_point;
		while (!(u == start_point)) {
			le++;
			u = path[u];
		}
		cout << "To get from " << a << " to " << b << " takes " << le << " knight moves." << endl;
	}
}