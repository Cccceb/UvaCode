#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("例题2in.txt", "r", stdin);
FILE *fout = freopen("例题2out.txt", "w", stdout);
#endif 
using namespace std;
struct job {
	int b, j;
	job(int b, int j) :b(b), j(j) {}
	bool operator > (const job&a)const { return j >a.j; }
};
vector<job> mis;
int main() {
	int n,kase = 0;
	while (cin >> n && n) {
		cout << "Case " << ++kase << ": ";
		mis.clear();
		int b, j;
		for (int i = 0; i < n; i++) {
			cin >> b >> j;
			mis.push_back(job(b, j));
		}
		
		sort(mis.begin(), mis.end(),greater<job>());
		int t = 0;
		int ans = 0;
		for (int i = 0; i < mis.size(); i++) {
			t += mis[i].b;//任务开始时间
			ans = max(ans, t + mis[i].j);//更新任务执行完毕时的最晚时间
		}
		cout << ans << endl;
	}
	
}