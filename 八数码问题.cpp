#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("八数码问题in.txt", "r", stdin);
FILE *fout = freopen("八数码问题out.txt", "w", stdout);
#endif

typedef int State[9];
const int maxstate = 1000000;
State st[maxstate], goal;
int dist[maxstate];
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
//set<int> vis;
//void init_lookup_table() { vis.clear(); }
//int try_to_insert(int s) {
//	int v = 0;
//	for (int i = 0; i < 9; i++) v = v * 10 + st[s][i];
//	if (vis.count(v)) return 0;
//	vis.insert(v);
//	return 1;
//}

/*
判重法二，哈希值法，非常的快，且通用。
*/
const int hashsize = 1000003;
int head[hashsize], next[hashsize];
void init_lookup_table() { memset(head, 0, sizeof(head)); }
int hash(State &s) {
	int v = 0;
	for (int i = 0; i < 9; i++) v = v * 10 + s[i];
	return v % hashsize;
}
int try_to_insert(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while (u) {
		if (memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;//对s节点建立双向链表
	return 1;
}
int bfs() {
	init_lookup_table();
	int front = 1, rear = 2;
	while (front < rear) {
		State& s = st[front];
		if (memcmp(goal, s, sizeof(s)) == 0) 
			return front;
		int z;
		for (z = 0; z < 9; z++) if (!s[z]) break;//找到"0"的位置
		int x = z / 3, y = z % 3;
		for (int d = 0; d < 4; d++) {
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
				State &t = st[rear];
				memcpy(&t, &s, sizeof(s));
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front] + 1;
				if (try_to_insert(rear)) rear++;
			}
		}
		front++;
	}
	return 0;
}
int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
	for (int i = 0; i < 9; i++)scanf("%d", &goal[i]);
	int ans = bfs();
	if (ans > 0) printf("%d\n", dist[ans]);
	else printf("-1\n");

	return 0;
}