#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚6-7in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚6-7out.txt", "w", stdout);
#endif 
using namespace std;
int NP, NT, kase = 0;;
const int maxn = 100;
int p[maxn];
map<vector<int>, vector<int>> t[maxn];
int main() {

	while (cin >> NP && NP) {
		getchar();
		memset(p, 0, sizeof(p));
		for (int i = 0; i < maxn; i++) 
			t[i].clear();

		for (int i = 1; i <= NP; i++)
			scanf("%d", &p[i]);
		cin >> NT; getchar();
		string s;
		for (int i = 1; i <= NT; i++) {
			getline(cin, s);
			stringstream ss(s);
			int xx;
			vector<int> po;
			vector<int> ne;
			while (ss >> xx) {
				if (xx > 0) po.push_back(xx);
				if (xx < 0)ne.push_back(abs(xx));
			}
			map<vector<int>, vector<int>> tmp;
			tmp[ne] = po;
			t[i] = tmp;
		}
		int firings;
		cin >> firings;
		int cnt = 0;
		for (int i = 1; i <= NT; i++) {
			auto it = t[i].begin();
			bool flag = true;

			for (int j = 0; j < it->first.size(); j++)
			{
				int index = it->first[j];

				p[index]--;
				if (p[index] < 0) flag = false;
			}

			if (flag)
				for (int j = 0; j < it->second.size(); j++)

					p[it->second[j]]++;


			else {
				for (int j = 0; j < it->first.size(); j++)
					p[it->first[j]]++;
				continue;
			}

			i = 0;
			if (++cnt >= firings) break;
		}
		if (cnt >= firings) printf("Case %d: still live after %d transitions\n", ++kase, firings);
		else printf("Case %d: dead after %d transitions\n", ++kase, cnt);
		printf("Places with tokens:");
		for (int i = 1; i <= NP; ++i) if (p[i]) printf(" %d (%d)", i, p[i]);
		printf("\n\n");


	}


}
