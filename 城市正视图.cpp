/*
p132 uva221
*/
#include<iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("城市正视图in.txt", "r", stdin);
FILE *fout = freopen("城市正视图out.txt", "w", stdout);
#endif 
using namespace std;
struct bulid {
	double x, y, w, d, h;
	int id;
	bool operator <(const bulid&r) const{ return x < r.x || x == r.x&&y < r.y; }
}b[105];
int n;
bool cover(int id, double mx) {
	return mx >= b[id].x && mx <= b[id].x + b[id].w;
}
bool visable(int id, double mx) {
	if (!cover(id, mx)) return false;
	for (int i = 0; i < n; i++) {
		if (b[i].y < b[id].y&&b[i].h >= b[id].h&&cover(i, mx)) return false;
	}
	return true;
}
int main() {

	
	int kase = 0;
	int first = 1;
	while (cin >> n && n) {
		if (first) first = 0;
		else cout << endl;

		int x[2*105]{};
		for (int i = 0; i < n; i++) {
			cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
			b[i].id = i + 1;
			x[2 * i] = b[i].x;
			x[2 * i + 1] = b[i].x + b[i].w;
		}

		sort(b, b + n);
		sort(x, x + 2 * n);
		int m = unique(x, x + 2 * n) - x;
		cout << "For map #" <<++kase << ", the visible buildings are numbered as follows:" << endl;
		cout << b[0].id ;
			for (int i = 1; i < n; i++) {
				bool vis = false;
				for (int j = 0; j < m - 1; j++) {
					if (visable(i, (x[j] + x[j + 1]) / 2)) {
						vis = true;
						break;
					}

				}
				if (vis) cout <<" "<< b[i].id;

			}
			cout << "\n";
	}
}