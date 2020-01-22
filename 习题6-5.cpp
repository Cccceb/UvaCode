#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ϰ��6-5in.txt", "r", stdin);
FILE *fout = freopen("ϰ��6-5out.txt", "w", stdout);
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
				if (step[r][c] < u.k) {//u.k���ߵ�step[r][c]������ʣ��������ϰ��Ļ��ᣬ����Ҫ�������
					step[r][c] = u.k;
				}
				else continue;//���step[r][c]����˵��Ŀǰ�����ߵ�·������õ�(��Ϊbfs�ߵ�ÿ���ڵ�Ĳ�����һ����
							  //����ʣ��Ŀ�Խ�ϰ��Ĵ���Խ��Խ��),����Ҫ������ȥ�����Բ����)
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