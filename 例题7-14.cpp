#include<iostream>
#include<algorithm>
#include<set>
#pragma warning(disable:4996)
FILE *fin = freopen("例题7-14in.txt", "r", stdin);
FILE *fout = freopen("例题7-14out.txt", "w", stdout);
using namespace std;
struct node {
	int r, c;
	node(int r = 0, int c = 0) :r(r), c(c) {}
	bool operator < (const node &a) const { return r < a.r || r == a.r && c < a.c; }
};
typedef set<node> g;
const int maxn = 10;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
g normal(const g& p);
g turn(const g& p);
g filp(const g& p);
void insert(const g& p, node nd);
void get_ans();
int ans[maxn + 1][maxn + 1][maxn + 1];
set<g> animals[maxn + 1]; //animals表示所有i个块的连通块的集合
g normal(const g& p) {
	int minx = p.begin()->r, miny = p.begin()->c;
	for (g::iterator i = p.begin(); i != p.end(); i++) {
		minx = min(minx, i->r);
		miny = min(miny, i->c);
	}
	g p2;
	for (g::iterator i = p.begin(); i != p.end(); i++)
		p2.insert(node(i->r - minx, i->c - miny));
	return p2;
}
g turn(const g&p) {
	g p2;
	for (g::iterator i = p.begin(); i != p.end(); i++)
		p2.insert(node(i->c, -i->r));
	return normal(p2);
}
g filp(const g&p) {
	g p2;
	for (g::iterator i = p.begin(); i != p.end(); i++)
		p2.insert(node(i->r, -i->c));
	return normal(p2);
}
void insert(const g& p, node nd) {
	g p2 = p;
	p2.insert(nd);
	p2 = normal(p2);
	int n = p2.size();

	for (int i = 0; i < 4; i++) {
		if (animals[n].count(p2)) return;
		p2 = turn(p2);
	}
	p2 = filp(p2);
	for (int i = 0; i < 4; i++) {
		if (animals[n].count(p2)) return;
		p2 = turn(p2);
	}
	animals[n].insert(p2);
}
void get_ans() {
	g start;
	start.insert(node(0, 0));
	animals[1].insert(start);
	for (int i = 2; i <= maxn; i++)
		for (set<g>::iterator j = animals[i - 1].begin(); j != animals[i - 1].end(); j++)
			for (g::iterator k = (*j).begin(); k != (*j).end(); k++) {
				int r = k->r, c = k->c;
				for (int w = 0; w < 4; w++) {
					node nd(r + dx[w], c + dy[w]);
					if (!(*j).count(nd))
						insert(*j, nd);
				}
			}


	for (int n = 1; n <= maxn; n++)
		for (int w = 1; w <= maxn; w++)
			for (int h = 1; h <= maxn; h++) {
				int sum = 0;
				for (set<g>::iterator p = animals[n].begin(); p != animals[n].end(); p++) {
					int maxx = 0, maxy = 0;
					for (g::iterator q = (*p).begin(); q != (*p).end(); q++) {
						maxx = max(maxx, q->r);
						maxy = max(maxy, q->c);
					}
					if (max(maxx, maxy) < max(w, h) && min(maxx, maxy) < min(w, h)) sum++;
				}
				ans[n][w][h] = sum;
			}
}
int main()
{
	int n, h, w;
	get_ans();
	while (cin >> n >> w >> h)
		cout << ans[n][w][h] << endl;
	return 0;
}
