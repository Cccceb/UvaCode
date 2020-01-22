#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("AbbottµÄ¸´³ðin.txt", "r", stdin);
FILE *fout = freopen("AbbottµÄ¸´³ðout.txt", "w", stdout);
#endif 
using namespace std;
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };
struct Node {
	int r;
	int c;
	int dir;
	Node() {};
	Node(int r, int c, int dir = -5) :r(r), c(c), dir(dir) {}
	bool operator<(const Node &a) const {
		return r < a.r || r == a.r&&c < a.c || r == a.r&&c == a.c&&dir < a.dir;
	}
	bool operator!=(const Node &a) const {
		return r != a.r || c != a.c || dir != a.dir;
	}
};
Node sta, over;
string dirs = "NESW";
int dir_id(char c) { return dirs.find(c); }
string turns = "FLR";
int turn_id(char c) { return turns.find(c); }

map<int, map<int, map<int, set<int>>>> maze;//r,c,dir,turn
set<Node>have_travel;
map<Node, Node> path;


Node walk(const Node &u, int turn) {
	int dir = u.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}
int main() {
	string name;
	while (getline(cin, name) && name != "END")
	{
		path.clear();
		have_travel.clear();
		maze.clear();
		cout << name << endl << " ";
		char ch;
		cin >> sta.r >> sta.c >> ch >> over.r >> over.c;
		sta.dir = dir_id(ch);

		int a = sta.r, b = sta.c;

		sta.r += dr[sta.dir];
		sta.c += dc[sta.dir];



		int r, c;
		while (cin >> r && r) {
			cin >> c;
			string s;
			while (cin >> s && s != "*") {

				for (int i = 1; i < s.length(); i++) {
					maze[r][c][dir_id(s[0])].insert(turn_id(s[i]));

				}
			}

		}
		getchar();
		queue<Node> q;
		vector<Node> ans;

		bool flag = false;
		if (sta.c == over.c && sta.r == over.r) {
			flag = true;
		}
		else {
			q.push(sta);
			ans.push_back(over);
		}

		while (!q.empty()) {
			Node u = q.front(); q.pop();
			if (u.r == over.r&&u.c == over.c) {
				over = u;
				flag = true;
				break;
			}
			for (int i = 0; i < 3; i++) {

				Node v = walk(u, i);
				if (maze[u.r][u.c][u.dir].count(i)
					&& !have_travel.count(v)
					)
				{
					have_travel.insert(v);
					path[v] = u;
					q.push(v);
				}

			}


		}
		if (!flag) {
			cout << " No Solution Possible" << endl;
			continue;
		}
		Node u = path[over];


		while (u != sta) {
			if (!path.count(u)) break;
			ans.push_back(u);
			u = path[u];
		}
		ans.push_back(sta);
		ans.push_back(Node(a, b, 0));

		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << " (" << ans[i].r << "," << ans[i].c << ")";
			if ((ans.size() - i) % 10 == 0 && i) cout << endl << " ";
		}
		cout << endl;
	}
}