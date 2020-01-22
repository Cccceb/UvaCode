#include <bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("习题7-4in.txt", "r", stdin);
FILE *foout = freopen("习题7-4out.txt", "w", stdout);
#define inf 1e8+7
using namespace std;
const int maxn = 25;
int used[maxn], mapp[maxn][maxn];
int n, num, ans, a, b, cas;

bool dfs(int u, int fa, int s)
{
	used[u] = 1;
	for (int i = 0; i < n; i++)
	{
		if (mapp[u][i])
		{
			if (i == fa || (s & (1 << i)))	continue;
			if (used[i])	return 1;
			if (dfs(i, u, s))	return 1;
		}
	}
	return 0;
}

bool have_two(int s)
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (mapp[i][j] && !(s & (1 << i)) && !(s & (1 << j)))//s!=(1<<i)&&s!=(1<<j)，因为s状态下某个环破开了
			{
				cnt++;
				if (cnt > 2)
					return 1;
			}
		}
	}
	return 0;
}

bool have_circle(int s)
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++)
	{
		if (!used[i] && !(s & (1 << i)))
		{
			num++;
			if (dfs(i, -1, s))return 1;
		}
	}
	return 0;
}

int calc(int s)
{
	int cnt = 0;
	for (int j = 0; j < n; j++)
	{
		if (s & (1 << j))cnt++;
	}
	return cnt;
}

void solve()
{
	ans = inf;
	for (int i = 0; i < (1 << n); i++)
	{
		num = 0;
		if (have_two(i) || have_circle(i))continue;
		int count = calc(i);
		if (num - 1 <= count)ans = min(ans, count);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF && n)
	{
		memset(mapp, 0, sizeof(mapp));
		while (scanf("%d%d", &a, &b) != EOF && a != -1 && b != -1)
		{
			mapp[a - 1][b - 1] = 1;
			mapp[b - 1][a - 1] = 1;
		}
		solve();
		printf("Set %d: Minimum links to open is %d\n", ++cas, ans);
	}
}