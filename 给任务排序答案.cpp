//������if�����в�Ҫ����if(flag[i] == 1)���������;��ø�Ϊ if(flag[i])
#include <iostream>
#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����������in.txt", "r", stdin);
FILE *fout = freopen("����������out.txt", "w", stdout);
#endif 
using namespace std;
const int maxn = 1000 + 5;

int g[maxn][maxn];      //g[i][j] = 1 ����i����Ҫ����j�������
int flag[maxn];             //1�����Ѿ����ʹ��ˣ�-1�������ڷ��ʣ�0����δ����
int ans[maxn];              //�����
int m, n, t;   //m��ʾ��ϵ������n�����ж��ٸ�����

bool dfs(int u) {
	flag[u] = -1;
	for (int v = 0; v < n; v++) {
		if (g[u][v]) {
			if (flag[v] < 0)   return false;
			else if (!flag[v])   dfs(v);
		}
	}
	flag[u] = 1;
	ans[--t] = u;   //ע����Ϊdfs�ǵݹ�ʵ�ֵģ����Ա���������һ���ڵ�������������ز����е��ײ�
	return true;
}

bool topoSort() {
	t = n;
	for (int i = 0; i < n; i++) {
		if (!flag[i])
			if (!dfs(i))     return false;
	}
	return true;
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);  a--; b--;
			g[a][b] = 1;    //��Ϊ�����Ǵ�1��ʼ�Ľڵ㣬���Դ洢��ȥ��ʱ������һ
		}

		memset(flag, 0, sizeof(flag));
		if (topoSort()) {        //���ز���������н���ѹ��ans��
			for (int i = 0; i < n - 1; i++)
				printf("%d ", ans[i] + 1);
			printf("%d\n", ans[n - 1] + 1);
		}
		else
			printf("No\n");
	}
	return 0;
}
