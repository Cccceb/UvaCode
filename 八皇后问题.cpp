/*
恰好每行每列各放置一个皇后，如果用A[x]表示第x行皇后的列号，则问题变成了一个
全排列生成问题。
*/
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("八皇后in.txt", "r", stdin);
FILE *fout = freopen("八皇后out.txt", "w", stdout);
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
			//对于(i,cur)
			//以cur+i来标识副对角线，cur-i来标识主对角线，由于主对角线可能为负
			//所以要加上n
			A[cur] = i + 1;
			//对于(cur,i)处要么有子要么无子-->回溯的两种情况
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;//非常关键，回溯法中修改的辅助
																 //局部变量，一定要及时恢复原状
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	search(0);
	cout << tot << endl;
}