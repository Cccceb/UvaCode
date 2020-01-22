#include<iostream>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ5-3in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ5-3out.txt", "w", stdout);
#endif 
using namespace std;
int n;
int main() {
	while (cin >> n && n) {
		queue<int> q;
		bool first = true;
		for (int i = 0; i < n; i++) {
			q.push(i + 1);
		}
		cout << "Discarded cards:";
		while (q.size() > 1) {
			if (first) first = false;
			else cout << ",";
			cout << " " << q.front();
			q.pop();
			q.push(q.front());
			q.pop();
		}

		cout << endl <<"Remaining card: "<< q.front()<< endl;
	}
}