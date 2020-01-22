#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚5-10in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚5-10out.txt", "w", stdout);
#endif 
using namespace std;

vector<string> txt[105];
map<string, set<int>> which_pa;
struct node {
	int p;
	int r;
	node(int p, int r) :p(p), r(r) {}
	bool operator <(const node&a) const {
		return p < a.p || p == a.p&&r < a.r;
	}
};
map<string, set<node>> words_in_where;
int main() {
	int n, m;
	string s;
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; i++) {

		while (getline(cin, s) && s != "**********") {
			txt[i].push_back(s);
			string r;
			for (int j = 0; j < s.length(); j++) {
				if (isalpha(s[j])) r += tolower(s[j]);
				else {
					if (!r.empty()) {
						words_in_where[r].insert(node(i, txt[i].size() - 1));
						which_pa[r].insert(i);
					}
					r.clear();
				}
			}
		}
	}



	scanf("%d", &m); getchar();
	for (int ff = 0; ff < m; ff++) {
		getline(cin, s);
		int orx;
		//cout << endl << s << endl << endl;
		if ((orx = s.find(" AND ")) != string::npos) {
			string a = s.substr(0, orx);
			string b = s.substr(orx + 5);
			//	cout << a << " " << b << endl;
			set<node> aw = words_in_where[a];
			set<node> bw = words_in_where[b];
			set<node> ans;
			ans.clear();
			if (a == b) {
				for (set<node>::iterator it = aw.begin(); it != aw.end(); it++)
					ans.insert(*it);
			}
			else {
				for (set<node>::iterator it = aw.begin(); it != aw.end(); it++)
					for (set<node>::iterator id = bw.begin(); id != bw.end(); id++)
						if ((*it).p == (*id).p) {
							ans.insert(*it);
							ans.insert(*id);
						}
			}

			if (ans.empty()) {
				cout << "Sorry, I found nothing." << endl << "==========" << endl;
				continue;
			}
			int k = ans.begin()->p;
			for (set<node>::iterator it = ans.begin(); it != ans.end(); it++)
			{
				int p = (*it).p;
				int r = (*it).r;
				if (k != p) {
					cout << "----------" << endl;
					k = p;
				}
				cout << txt[p][r] << endl;
			}


			cout << "==========" << endl;
		}
		else if ((orx = s.find(" OR ")) != string::npos) {
			string a = s.substr(0, orx);
			string b = s.substr(orx + 4);
			//cout << a << " " << b << endl;
			set<node> aw = words_in_where[a];
			set<node> bw = words_in_where[b];
			set<node> ans;
			ans.clear();
			if (a == b) {
				for (set<node>::iterator it = aw.begin(); it != aw.end(); it++) {
					ans.insert(*it);
				}
			}
			else {
				for (set<node>::iterator it = aw.begin(); it != aw.end(); it++)
					ans.insert(*it);
				for (set<node>::iterator id = bw.begin(); id != bw.end(); id++)
					ans.insert(*id);
			}

			if (ans.empty()) {
				cout << "Sorry, I found nothing." << endl << "==========" << endl;
				continue;
			}
			int k = ans.begin()->p;
			for (set<node>::iterator it = ans.begin(); it != ans.end(); it++)
			{
				int p = (*it).p;
				int r = (*it).r;
				if (k != p) {
					cout << "----------" << endl;
					k = p;
				}
				cout << txt[p][r] << endl;
			}


			cout << "==========" << endl;
		}
		else if (s[0]=='N') {
			string no = s.substr(4);
			//cout << no << endl;
			bool flag = false;
			bool first = true;
			for (int i = 0; i < n; i++) {
				if (!which_pa[no].count(i)) {
					if (first) first = false; else cout << "----------" << endl;
					for (int j = 0; j < txt[i].size(); j++)
						cout << txt[i][j] << endl;
					flag = true;
				}

			}

			if (flag) cout << "==========" << endl;
			else cout << "Sorry, I found nothing." << endl << "==========" << endl;
		}
		else {
			//cout << s << endl;
			if (!words_in_where.count(s)) {
				cout << "Sorry, I found nothing." << endl << "==========" << endl;
				continue;
			}
			int k = words_in_where[s].begin()->p;
			for (set<node>::iterator it = words_in_where[s].begin(); it != words_in_where[s].end(); it++) {
				int p = (*it).p;
				int r = (*it).r;
				if (k != p) {
					cout << "----------" << endl;
					k = p;
				}
				cout << txt[p][r] << endl;
			}
			//if (first) cout << "Sorry, I found nothing." << endl;
			cout << "==========" << endl;
		}
	}

}
