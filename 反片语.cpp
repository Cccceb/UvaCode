#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("∑¥∆¨”Ôin.txt", "r", stdin);
FILE *fout = freopen("∑¥∆¨”Ôout.txt", "w", stdout);
#endif 
using namespace std;
vector<string>word;
map<string, int> cnt;
string standard(const string &in) {
	string s = in;
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	sort(s.begin(), s.end());
	return s;
}
int main() {
	string s;
	while (cin >> s) {
		if (s[0] == '#')	break;
		word.push_back(s);
		string r = standard(s);
		if (!cnt.count(r)) cnt[r] = 0;
		cnt[r]++;
	}
	vector<string> ans;
	for (int i = 0; i < word.size(); i++) {
		if (cnt[standard(word[i])] == 1) ans.push_back(word[i]);
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}
