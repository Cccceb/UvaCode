#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ï°Ìâ5-6in.txt", "r", stdin);
FILE *fout = freopen("Ï°Ìâ5-6out.txt", "w", stdout);
#endif 
using namespace std;
int n;
int main() {
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		map<int, vector<int>> dk;
		set<double> avgx;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x>> y;
			dk[y].push_back(x);
		}

		for (map<int, vector<int>>::iterator it = dk.begin(); it != dk.end(); it++) {
			int sum=0;
			for (int j = 0; j < it->second.size(); j++) {
				sum += it->second[j];
			}
			//cout << "sum  " << sum << endl;
			avgx.insert((double)sum /(double) it->second.size());
		}

		avgx.size() == 1 ? cout << "YES" << endl : cout << "NO" << endl;
	}
}