/*
ǡ��ÿ��ÿ�и�����һ���ʺ������A[x]��ʾ��x�лʺ���кţ�����������һ��
ȫ�����������⡣
*/
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("�˻ʺ�in.txt", "r", stdin);
FILE *fout = freopen("�˻ʺ�out.txt", "w", stdout);
#endif 
using namespace std;
int print_num = 1;
int tot = 0;
int n;
int A[100];
int vis[100][100];
void search(int cur) {
	ios::sync_with_stdio(false);
	if (cur == n) {
		if (print_num <= 3) {
			cout << A[0];
			for (unsigned int i = 1; i < n; i++)
				cout << " "<< A[i] ;
			cout << endl;
			print_num++;
		}
		tot++;
	}
	else for (unsigned int i = 0; i < n; i++) {
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
			//����(i,cur)
			//��cur+i����ʶ���Խ��ߣ�cur-i����ʶ���Խ��ߣ��������Խ��߿���Ϊ��
			//����Ҫ����n
			A[cur] = i + 1;
			//����(cur,i)��Ҫô����Ҫô����-->���ݵ��������
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;//�ǳ��ؼ������ݷ����޸ĵĸ���
																 //�ֲ�������һ��Ҫ��ʱ�ָ�ԭ״
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	search(0);
	cout << tot << endl;
}