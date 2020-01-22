/*
p117 例5-6 UVA540
*/
#include<iostream>
#include<string>
#include<map>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("团体队列in.txt", "r", stdin);
FILE *fout = freopen("团体队列out.txt", "w", stdout);
#endif 
using namespace std;
int main() {
	int kase = 0;
	for (;;) {
		map<int, int> belong;
		queue<int> total,team[1100];
		int n;
		cin >> n;
		if (!n) return 0;
		cout << "Scenario #" << ++kase << endl;
		for(int i=0;i<n;i++) {
			int m;
			cin >> m;
			while(m--) {
				int x;
				cin >> x;
				belong[x] = i;
			}
		}


		for (;;) {
			string cmd;
			cin >> cmd;
			if (cmd[0] == 'S') break;
			else {
				if (cmd[0] == 'D') {
					int t = total.front();
					cout << team[t].front() << endl;
					team[t].pop();
					if (team[t].empty()) total.pop();

				}
				if (cmd[0] == 'E') {
					int num;
					cin >> num;
					int t = belong[num];
					if (team[t].empty()) total.push(t);
					team[t].push(num);
				}
			}
		}
		cout << endl;
	}
}