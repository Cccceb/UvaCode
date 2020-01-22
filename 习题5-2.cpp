#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题5-2in.txt", "r", stdin);
FILE *fout = freopen("习题5-2out.txt", "w", stdout);
#endif 
using namespace std;
int n;
vector<int> li;
int main() {
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		li.clear();
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			li.push_back(x);
		}
		vector<int> next;
		int i;
		for (i = 0; i < 1000; i++) {//次数
			bool flag = true;
			for (int k = 0; k < li.size(); k++)
				if (li[k])
					flag = false;
			if (flag) 
				break;
			for (int j = 0; j < li.size(); j++) {//循环序列
				if (j < li.size() - 1) next.push_back(abs(li[j] - li[j + 1]));
				else next.push_back(abs(li[j] - li[0]));
			}

			li.clear();
			li = next;
			next.clear();
		}
		if (i == 1000) cout << "LOOP" << endl;
		else cout << "ZERO" << endl;
	}
}