//尽量用if条件中不要包含if(flag[i] == 1)这样的语句;最好改为 if(flag[i])
#include <iostream>
#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("给任务排序in.txt", "r", stdin);
FILE *fout = freopen("给任务排序out.txt", "w", stdout);
#endif 
using namespace std;
const int maxn = 1000 + 5;

int g[maxn][maxn];      //g[i][j] = 1 代表i任务要优先j任务完成
int flag[maxn];             //1代表已经访问过了，-1代表正在访问，0代表未访问
int ans[maxn];              //保存答案
int m, n, t;   //m表示关系数量，n代表有多少个任务

bool dfs(int u) {
	flag[u] = -1;
	for (int v = 0; v < n; v++) {
		if (g[u][v]) {
			if (flag[v] < 0)   return false;
			else if (!flag[v])   dfs(v);
		}
	}
	flag[u] = 1;
	ans[--t] = u;   //注意因为dfs是递归实现的，所以遍历访问完一个节点后必须把它放在拓补序列的首部
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
			g[a][b] = 1;    //因为题意是从1开始的节点，所以存储进去的时候必须减一
		}

		memset(flag, 0, sizeof(flag));
		if (topoSort()) {        //在拓补排序过程中将答案压入ans中
			for (int i = 0; i < n - 1; i++)
				printf("%d ", ans[i] + 1);
			printf("%d\n", ans[n - 1] + 1);
		}
		else
			printf("No\n");
	}
	return 0;
}
