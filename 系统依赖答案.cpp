#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("系统依赖in.txt", "r", stdin);
FILE *fout = freopen("系统依赖out.txt", "w", stdout);
#endif 
using namespace std;
const int maxn = 10000;
int cnt, status[maxn];
string name[maxn];
map<string, int>ids;
vector<int> depend[maxn], depend2[maxn], installed;
int get_id(string s) {
	if (ids.count(s)) return ids[s];
	name[cnt] = s;
	return ids[s] = cnt++;
}
bool needed(int item) {
	for (int i = 0; i < depend2[item].size(); ++i)
		if (status[depend2[item][i]]) return true;
	return false;
}
void install(int item, bool toplevel) {
	if (!status[item]) {
		for (int i = 0; i < depend[item].size(); i++)
			install(depend[item][i], false);
		cout << "   Installing " << name[item] << '\n';
		status[item] = toplevel ? 1 : 2;
		installed.push_back(item);
	}
}
void remove(int item, bool toplevel) {
	if ((toplevel || status[item] == 2) && !needed(item)) {
		status[item] = 0;
		installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
		cout << "   Removing " << name[item] << '\n';
		for (int i = 0; i < depend[item].size(); i++)
			remove(depend[item][i], false);
	}
}
int main()
{

	ios::sync_with_stdio(false);
	string s, cmd;
	while (getline(cin, s)) {
		cout << s << '\n';
		if (s[0] == 'E') break;
		stringstream ss(s);
		ss >> cmd;
		if (cmd[0] == 'L') {
			for (int i = 0; i < installed.size(); ++i)
				cout << "   " << name[installed[i]] << '\n';
		}
		else {
			int id1, id2;
			string s1, s2;
			ss >> s1;
			id1 = get_id(s1);
			if (cmd[0] == 'D') {
				while (ss >> s2) {
					id2 = get_id(s2);
					depend[id1].push_back(id2);
					depend2[id2].push_back(id1);
				}
			}
			if (cmd[0] == 'I')
			{
				if (status[id1]) cout << "   " << s1 << " is already installed.\n";
				else install(id1, true);
			}
			if (cmd[0] == 'R') {

				if (!status[id1]) cout << "   " << s1 << " is not installed.\n";
				else if (needed(id1)) cout << "   " << s1 << " is still needed.\n";
				else remove(id1, true);
			}

		}
	}
	return 0;
}