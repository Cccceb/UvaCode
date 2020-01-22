#include<cstdio>
#include<set>
#include<map>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("例题7-9in.txt", "r", stdin);
FILE *fout = freopen("例题7-9out.txt", "w", stdout);
#endif
using namespace std;
#define p pair<int,int>
#define rint register int 
int r, c, s;//r行c列s个鬼
struct node {
	p loc[3];
	int dist;
	bool operator <(const node&a) const {
		return dist > a.dist;
	}
	bool operator ==(const node &a) const {
		return loc[0] == a.loc[0] && loc[1] == a.loc[1] && loc[2] == a.loc[2];
	}
};
struct location {
	p loc[2];

	location(node a) {
		loc[0] = a.loc[1];
		loc[1] = a.loc[2];
	}

	bool operator < (const location &a) const {
		return loc[0] < a.loc[0] || (loc[0] == a.loc[0] && loc[1] < a.loc[1]);
		//return loc[0] == a.loc[0] && loc[1] == a.loc[1] && loc[2] == a.loc[2];
	}
};
node end_stu, start;
map<p, vector<p>> blank;
map<p, set<location>> vis;
bool isOk(node, node);
void bfs();
void read_in();
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,1,-1 };
char g[260][260];
int main() {
	while (scanf("%d%d%d", &c, &r, &s) && r) {
		read_in();
		bfs();
	}
}
bool isOk(p a1, p a2, p b1, p b2) {
	if ((a2 == b1 && a1 == b2) || a2 == b2 )
		return false;
	return true;
}
inline void bfs() {
	vis.clear();
	queue<node> q;
	start.dist = 0;
	q.push(start);
	vis[start.loc[0]].insert(start);
	while (!q.empty())
	{
		node u = q.front(); q.pop();
		p a, b, c;
		if (u == end_stu) {
			printf("%d\n", u.dist);
			return;
		}
		node v;
		v.dist = u.dist + 1;
		for (rint i = 0; i<blank[u.loc[0]].size(); i++) {
			a = u.loc[0];
			a.first += dx[i];
			a.second += dy[i];
			for (rint j = 0; j < blank[u.loc[1]].size(); j++) {
				b = u.loc[1];
				if (b.first != -1) {
					b.first += dx[j];
					b.second += dy[j];
					if (!isOk(u.loc[0], a, u.loc[1], b)) continue;
				}

				for (rint k = 0; k < blank[u.loc[2]].size(); k++) {
					c = u.loc[2];
					if (c.first != -1) {
						c.first += dx[k];
						c.second += dy[k];
						if(!isOk(u.loc[0],a,u.loc[2],c)||!isOk(u.loc[1],b,u.loc[2],c))
							continue;
					}
					v.loc[0] = a;
					v.loc[1] = b;
					v.loc[2] = c;
					if (!vis[a].count(v) ) {
						vis[a].insert(v);
			
						q.push(v);
						//printf("%d %d,%d %d  %d\n", v.loc[0].first, v.loc[0].second, v.loc[1].first, v.loc[1].second, v.dist);
					}
				}
			}
		}


	}
	printf("-1\n");

}
inline void read_in() {
	blank.clear();
	char ch;
	p now;
	getchar();
	for (int i = 0; i < r; i++) {
		fgets(g[i], 20, stdin);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ch = g[i][j];
			if (ch == '#') continue;
			now.first = i;
			now.second = j;
			if (iswupper(ch)) end_stu.loc[ch - 'A'] = now;
			if (iswlower(ch)) start.loc[ch - 'a'] = now;
			for (int k = 0; k < 5; k++) {
				p next = p(now.first + dx[k], now.second + dy[k]);
				if (g[next.first][next.second] != '#')
					blank[now].push_back(next);
			}
			
		}
	}
	if (s == 3) return;
	if (s <= 2) {
		start.loc[2] = p(-1, -1);
		end_stu.loc[2] = p(-1, -1);

	}
	if (s <= 1) {
		start.loc[1] = p(-1, -1);
		end_stu.loc[1] = p(-1, -1);

	}

}