#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("例题7-10in.txt", "r", stdin);
FILE *fout = freopen("例题7-10out.txt", "w", stdout);
using namespace std;
#define rint register int 
const int maxn = 15;
int maxd;
int  T;
int in[maxn][maxn];
bool dfs(int d);
inline int not_inorder(int d) {
	int ret(0);
	for (int i(0); i < T - 1; ++i)
		ret += in[d][i + 1] != in[d][i] + 1;
	return ret + (in[d][T - 1] != (T - 1));

}

int main() {
	int kase = 0;
	while (scanf("%d", &T) && T)
	{
		for (int i = 0; i < T; i++) {
			scanf("%d", &in[0][i]);
			--in[0][i];
		}
		for (maxd = 0; maxd <= T; maxd++) {
			if (dfs(0)) break;
		}

		printf("Case %d: %d\n", ++kase, maxd);
	}
}
bool dfs(int d) {
	if (d == maxd) 
		return not_inorder(d) == 0;
	if (d * 3 + not_inorder(d) > 3 * maxd) return false; //每次剪切时后继不正确的数字个数至多减少三个
														//考虑abc变成acb，那么受影响的至多是a b c的最后一个数

	//枚举剪切的起始位置和长度
	int next = d + 1;
	for (rint len = 0; len < T; len++) {
		for (rint start = 0; start <= T - len; start++) {


			//如果试图剪切有序串，那么剪枝
			if (start > 0 && in[d][start - 1] == in[d][start] - 1) continue;
			if (start + len < T && in[d][start + d - 1] == in[d][start + d] - 1) continue;

			//枚举粘贴的起始位置
			for (rint pos = 0; pos <= T - len; pos++)
			{
				//也不能粘到自己里面
				if (pos >= start && pos < start + len) continue;
				for (rint i = 0; i < T; i++) in[next][i] = in[d][i];
				//粘贴
				for (rint i = 0; i < len; i++)
					in[next][pos + i] = in[d][start + i];

				if (pos < start)
					for (rint i(pos); i < start; ++i)
						in[next][i + len] = in[d][i];
				else
					for (rint i(pos); i > start; --i)
						in[next][i - len] = in[d][i];
				if (dfs(next)) return true;
			}

		}
	}
	return false;
}