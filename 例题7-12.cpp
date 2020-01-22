#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("例题7-12in.txt", "r", stdin);
FILE *fout = freopen("例题7-12out.txt", "w", stdout);
int maxd;
int move[8][7] = {
{0,2,6,11,15,20,22},
{1,3,8,12,17,21,23},
{10,9,8,7,6,5,4},
{19,18,17,16,15,14,13},
{23,21,17,12,8,3,1},
{22,20,15,11,6,2,0},
{13,14,15,16,17,18,19},
{4,5,6,7,8,9,10}
};
int mid[8] = { 6,7,8,11,12,15,16,17 };
int op[8] = { 5,4,7,6,1,0,3,2 };
int state[50][24];
int ans[50], v[50];
int table[24];
inline int not_equal(int d);
bool dfs(int d);
inline bool update();
int cur_nm;
int main() {
	while (true)
	{
		memset(ans, -1, sizeof(ans));
		scanf("%d", &table[0]);
		if (!table[0]) break;
		for (int i = 1; i < 24; i++)
			scanf("%d", &table[i]);
		int p = 0;
		for (maxd = 0;; maxd++) {
			for (cur_nm = 1; cur_nm <= 3; cur_nm++) {//cur_nm当前的目标值
				memcpy(state[0], table, 24 * sizeof(int));
				if (dfs(0) && update()) 
					p = cur_nm;
			}
			if (p) break;
		}
		if (maxd)
			for (int i = 0; i < maxd; i++) printf("%c", ans[i] + 'A');
		else printf("No moves needed");
		printf("\n%d\n", p);
	}
}
bool dfs(int d) {
	if (d == maxd) {
		if (not_equal(d) == 0) return true;
		else return false;
	}
	int next = d + 1;
	if (d + not_equal(d) > maxd) return false;
	for (int i = 0; i < 8; i++) {
		if (d > 0 && op[v[d-1]]== i) continue;

		v[d] = i;
		memcpy(state[next], state[d], 24 * sizeof(int));
		for (int j = 0; j < 7; j++)
			state[next][move[i][j]] = state[d][move[i][(j + 1) % 7]];
		if (dfs(next)) return true;
	}
	return false;
}
bool update() {
	if (ans[0] != -1)
		for (int i = 0; i < maxd; i++)
			if (v[i] > ans[i]) return false;
			else if (v[i] < ans[i]) break;
	memcpy(ans, v, sizeof(int)*maxd);
	return true;
}
int not_equal(int d) {
	int ans = 0;
	for (int i = 0; i < 8; i++)
		if (state[d][mid[i]] != cur_nm)	ans++;
	return ans;
}