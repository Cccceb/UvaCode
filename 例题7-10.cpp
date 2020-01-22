#include<bits/stdc++.h>
#pragma warning(disable:4996)
FILE *fin = freopen("����7-10in.txt", "r", stdin);
FILE *fout = freopen("����7-10out.txt", "w", stdout);
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
	if (d * 3 + not_inorder(d) > 3 * maxd) return false; //ÿ�μ���ʱ��̲���ȷ�����ָ��������������
														//����abc���acb����ô��Ӱ���������a b c�����һ����

	//ö�ټ��е���ʼλ�úͳ���
	int next = d + 1;
	for (rint len = 0; len < T; len++) {
		for (rint start = 0; start <= T - len; start++) {


			//�����ͼ�������򴮣���ô��֦
			if (start > 0 && in[d][start - 1] == in[d][start] - 1) continue;
			if (start + len < T && in[d][start + d - 1] == in[d][start + d] - 1) continue;

			//ö��ճ������ʼλ��
			for (rint pos = 0; pos <= T - len; pos++)
			{
				//Ҳ����ճ���Լ�����
				if (pos >= start && pos < start + len) continue;
				for (rint i = 0; i < T; i++) in[next][i] = in[d][i];
				//ճ��
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