#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring> 
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����·��in.txt", "r", stdin);
FILE *fout = freopen("����·��out.txt", "w", stdout);
#endif 
using namespace std; //min()���� 
#define max 100000
#define inf 0x7fffffff
typedef struct ver {
	int num, color;//�ߵ���һ�˵Ľڵ��� �� ��ɫ 
	ver(int n, int c) :num(n), color(c) {}
}Ver;
int n, m, a, b, c;
int d[max], res[max];//d��¼ÿ���㵽�յ����̾��� res��¼���·����ɫ
bool vis[max], inqueue[max];//visÿ���ڵ��Ƿ񱻷��ʹ� inqueue��ǽڵ��Ƿ�����˶��У���ֹ�ظ����� 
vector<Ver> edge[max];//�ڽӱ��¼ͼ 
void bfs(int start, int end) {
	memset(inqueue, 0, n);
	memset(vis, 0, n);
	int u, v, c;
	queue<int> q;
	q.push(start);
	if (start == 0) {//��������bfs 
		memset(res, 0, sizeof(int)*n);
		while (!q.empty()) {
			u = q.front(); q.pop(); vis[u] = 1;
			if (u == n - 1)return;
			int minc = inf, len = edge[u].size();
			for (int i = 0; i < len; i++)
				if (!vis[v = edge[u][i].num] && d[u] - 1 == d[v])
					minc = min(edge[u][i].color, minc);//��ȡ����·������С����ɫ
			for (int i = 0; i < len; i++)
				if (!vis[v = edge[u][i].num] && d[u] - 1 == d[v] && edge[u][i].color == minc && !inqueue[v])
					q.push(v), inqueue[v] = 1; //���ж�����ɫ��ͬ,��δ��ӣ�������� 
			int index = d[0] - d[u];//��õ�ǰ������Ӧ���±�
			if (res[index] == 0)res[index] = minc;
			else res[index] = min(res[index], minc);//��ȡ��С��ɫ 
		}
	}//���ڷ���bfs �������ͼ�������· 
	else while (!q.empty()) {
		u = q.front(); q.pop(); vis[u] = 1;
		for (int i = 0, len = edge[u].size(); i < len; i++)if (!vis[v = edge[u][i].num] && !inqueue[v]) {
			d[v] = d[u] + 1; //һ����ͷһ����ӣ���ͨ��inqueue��֤ 
			if (v == 0)return; //�ҵ���㣬�˳� 
			q.push(v);//���������㣬�Ͱ��������� 
			inqueue[v] = 1;//��ӱ�� 
		}
	}
}
int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++)edge[i].clear();
		memset(d, -1, sizeof(int)*n); d[n - 1] = 0;//ע���ʼ����ϸ��
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			if (a != b) { //�ų��Ի�
				edge[a - 1].push_back(ver(b - 1, c));
				edge[b - 1].push_back(ver(a - 1, c));
			}
		}
		bfs(n - 1, 0);//����bfs
		bfs(0, n - 1);//����bfs 
		printf("%d\n%d", d[0], res[0]);
		for (int i = 1; i < d[0]; i++)printf(" %d", res[i]);
		printf("\n");
		
		for(int i=0;i<n;i++) cout<<d[i]<<endl; 
	}
}
