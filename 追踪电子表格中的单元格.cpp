/*
p85 例题 4-5
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("追踪in.txt", "r", stdin);
FILE *fout = freopen("追踪out.txt", "w", stdout);
#endif 
using namespace std;
typedef struct {
	char s[5];
	int r1, c1, r2, c2;
	int a, x[20];
}command;
command cmd[100000];
int r, c, n, m;
int simulate(int *r0, int *c0);
int main() {
	int kase = 0, first = 1;

	while (cin >> r >> c >> n && r&&c) {

		for (int i = 0; i < n; i++) {
			cin >> cmd[i].s;
			if (cmd[i].s[0] == 'E') {
				cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
			}
			else {
				cin >> cmd[i].a;
				for (int j = 0; j < cmd[i].a; j++) {
					cin >> cmd[i].x[j];
				}
			}
		}//表格和命令输入完成


		int r0, c0;
		cin >> m;
		if (first) first = 0;
		else cout << endl;
		cout << "Spreadsheet #" << ++kase << endl;
		for (int i = 0; i < m; i++) {
			cin >> r0 >> c0;
			cout << "Cell data in (" << r0 << "," << c0 << ") ";
			if (!simulate(&r0, &c0)) cout << "GONE" << endl;
			else cout << "moved to (" << r0 << "," << c0 << ")" << endl;
		}
	}

}
int simulate(int *r0, int *c0) {
	for (int i = 0; i < n; i++) {
		if (cmd[i].s[0] == 'E') {
			if (cmd[i].r1 == *r0&&cmd[i].c1 == *c0) {
				*r0 = cmd[i].r2;
				*c0 = cmd[i].c2;
			}
			else if (cmd[i].r2 == *r0&&cmd[i].c2 == *c0) {
				*r0 = cmd[i].r1;
				*c0 = cmd[i].c1;
			}
		}
		else {
			int dr = 0, dc = 0;

			for (int j = 0; j < cmd[i].a; j++) {
				int x = cmd[i].x[j];
				if (cmd[i].s[0] == 'I') {
					if (cmd[i].s[1] == 'R'&&x <= *r0) dr++;
					if (cmd[i].s[1] == 'C'&&x <= *c0) dc++;
				}
				else if (cmd[i].s[0] == 'D') {
					if (cmd[i].s[1] == 'R'&&x == *r0) return 0;
					if (cmd[i].s[1] == 'C'&&x == *c0) return 0;
					if (cmd[i].s[1] == 'R'&&x <= *r0) dr--;
					if (cmd[i].s[1] == 'C'&&x <= *c0) dc--;
				}
			}
			*r0 += dr;
			*c0 += dc;
		}
	}
	return 1;
}