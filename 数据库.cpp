#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("数据库in.txt", "r", stdin);
FILE *fout = freopen("数据库out.txt", "w", stdout);
#endif
using namespace std;
map<string, int> location;
set<string> same;
vector<int> str[100000];
typedef struct node {
	int x;
	int y;
	node(int x, int y) :x(x), y(y) {}
	bool operator < (const node& r) const { return x < r.x || x == r.x&&y < r.y; }
}point;
int main() {
	int r, c;
	while (scanf("%d%d", &r, &c) == 2) {
		getchar();
		same.clear();
		location.clear();
		for (int i = 0; i < r; i++) str[i].clear();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				string s;
				char cs = getchar();
				while (cs != ','&&cs != '\n') {
					s += cs;
					cs = getchar();
				}
				if (!same.count(s)) {
					location[s] = i * r + j;
					same.insert(s);
				}
				str[i].push_back(location[s]);
			}
		}
		/*for (int i = 0; i<str->size(); i++) {
			for (int j = 0; j < str[i].size(); j++)
				cout << str[i][j] << " ";
			cout << endl;
		}*/

		map<node, int> data;
		for (int c1 = 0; c1 < c; c1++) {
			for (int c2 = c1 + 1; c2 < c; c2++) {
				data.clear();
				for (int r1 = 0; r1 < r; r1++) {
					int x = str[r1][c1];
					int y = str[r1][c2];
					node p(x, y);
					if (!data.count(p)) data[p] = r1;
					else {
						cout << "NO" << endl << data[p] + 1 << " " << r1 + 1 << endl
							<< c1 + 1 <<" "<< c2 + 1 << endl;
						goto here;
					}
				}
			}
		}
		cout << "YES" << endl;
		here:;
	}
}