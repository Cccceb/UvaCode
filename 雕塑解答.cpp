#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;
int T;
const int maxn = 105;
const int maxr = 1e3 + 1;
int nx, ny, nz;

struct Point {
	int x, y, z;
	Point() {}
	Point(int x, int y, int z) :x(x), y(y), z(z) {}
};
Point p[maxn];
int x[maxn], y[maxn], z[maxn];
int a[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
long long V, S;
int getArea(int xx, int yy, int zz, int dir) {
	if (dx[dir])
		return (y[yy + 1] - y[yy])*(z[zz + 1] - z[zz]);
	if (dy[dir])
		return (x[xx + 1] - x[xx])*(z[zz + 1] - z[zz]);
	if (dz[dir])
		return (x[xx + 1] - x[xx])*(y[yy + 1] - y[yy]);
}

int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= 2 * n; i += 2) {
			cin >> x[i] >> y[i] >> z[i] >> x[i + 1] >> y[i + 1] >> z[i + 1];
			x[i + 1] += x[i];
			y[i + 1] += y[i];
			z[i + 1] += z[i];
			p[i].x = x[i];	p[i + 1].x = x[i + 1];
			p[i].y = y[i];	p[i + 1].y = y[i + 1];
			p[i].z = z[i];	p[i + 1].z = z[i + 1];//因为要重新排序去重

		}
		x[0] = 0;
		y[0] = 0;
		z[0] = 0;
		sort(x, x + 2 * n + 1);
		sort(y, y + 2 * n + 1);
		sort(z, z + 2 * n + 1);

		nx = unique(x, x + 2 * n + 1) - x;
		ny = unique(y, y + 2 * n + 1) - y;
		nz = unique(z, z + 2 * n + 1) - z;

		x[nx++] = maxr;
		y[ny++] = maxr;
		z[nz++] = maxr;

		for (int i = 1; i <= 2 * n; i += 2) {
			int x1, x2, y1, y2, z1, z2;
			x1 = lower_bound(x, x + nx, p[i].x) - x;
			x2 = lower_bound(x, x + nx, p[i + 1].x) - x;
			y1 = lower_bound(y, y + ny, p[i].y) - y;
			y2 = lower_bound(y, y + ny, p[i + 1].y) - y;
			z1 = lower_bound(z, z + nz, p[i].z) - z;
			z2 = lower_bound(z, z + nz, p[i + 1].z) - z;

			for (int xx = x1; xx < x2; xx++)
				for (int yy = y1; yy < y2; yy++)
					for (int zz = z1; zz < z2; zz++)
						a[xx][yy][zz] = 1;
		}
		V = 0;
		S = 0;
		queue<Point> q;
		q.push(Point(0, 0, 0));
		vis[0][0][0] = 1;
		while (!q.empty()) {
			Point u = q.front(); q.pop();
			V += (x[u.x + 1] - x[u.x])*(y[u.y + 1] - y[u.y])*(z[u.z + 1] - z[u.z]);

			for (int i = 0; i < 6; i++) {
				Point v = Point(u.x + dx[i], u.y + dy[i], u.z + dz[i]);

				if (v.x < 0 || v.x >= nx - 1 || v.y < 0 || v.y >= ny - 1 || v.z < 0 || v.z >= nz - 1)
					continue;
				if (a[v.x][v.y][v.z] == 1) {
					S += getArea(v.x, v.y, v.z, i);
				}
				else if (!vis[v.x][v.y][v.z]) {
					q.push(v);
					vis[v.x][v.y][v.z] = 1;
				}

			}

		}


		cout << S << " " << maxr*maxr*maxr - V << endl;

	}
}
