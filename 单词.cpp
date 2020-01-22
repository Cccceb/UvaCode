#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<string.h>

#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����.txt", "r", stdin);
FILE *fout = freopen("����.txt", "w", stdout);
#endif 

using namespace std;
map<int, set<int>> Adjacency;
int rudu[26];
int chudu[26];
int n, m, num;
int vis[26];
void dfs(int v) {

	vis[v] = 1;
	for (set<int>::iterator it = Adjacency[v].begin(); it != Adjacency[v].end(); it++) {
		if (!vis[*it]) dfs(*it);
	}

}

//������˵��������һ��ŷ��·����һҪ�ж��Ƿ��г���Ȳ���ȵĵ㣬�������ôһ����һ�����ȱ���ȴ�һ
//��һ����ȱȳ��ȴ�һ�����ȴ��Ϊ��㣩����Ҫ�ж��Ƿ���ͨ
void toposort() {
	memset(vis, 0, sizeof(vis));
	int st = Adjacency.begin()->first;//stΪŷ��·������㣬���ͼ�д��ڻ�����ôst���������ã�����
										//��Ҫ��ʼֵ���������ڣ���ôst������Ϊ���ȱ���ȴ�1�ĵ㡣
	num = 0;
	vector<int> diff;
	for (int i = 0; i < 26; i++) {
		if (rudu[i] != chudu[i]) {
			diff.push_back(i);
		}
	}
	if (diff.size() && diff.size() != 2) {
		num = 2;
		return;
	}
	else if (diff.size() == 2) {
		int a = rudu[diff[0]] - chudu[diff[0]];
		int b = rudu[diff[1]] - chudu[diff[1]];
		if (abs(a) != 1 || abs(b) != 1) {
			num = 2;
			return;
		}
		else {
			st = a > 0 ? diff[1] : diff[0];



		}
	}
	dfs(st);
	num++;
	for (map<int, set<int>>::iterator it = Adjacency.begin(); it != Adjacency.end(); it++) {
		if (!vis[it->first]) {

			num++;
			return;
		}
	}

}

int main() {
	cin >> m;
	for (int iii = 0; iii < m; iii++) {

		int x, y;
		Adjacency.clear();
		memset(rudu, 0, sizeof(rudu));
		memset(chudu, 0, sizeof(chudu));
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			x = s[0] - 'a';
			y = s[s.length() - 1] - 'a';
			Adjacency[x].insert(y);
			rudu[y]++;
			chudu[x]++;
		}
		if (n != 1) toposort();
		else num = 1;
		if (n == 2 && Adjacency.size() == 1) num++;
		num == 1 ? cout << "Ordering is possible." << endl : cout << "The door cannot be opened." << endl;
	}
}