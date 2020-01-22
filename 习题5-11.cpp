#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚5-11in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚5-11out.txt", "w", stdout);
#endif 
using namespace std;
int T;
void print(set<string> add,string op) {
	bool first = true;
	for (set<string>::iterator it = add.begin(); it != add.end(); it++) {
		if (first) {
			first = false;
			cout << op;
		}
		else cout << ",";
		cout << *it;
	}
	cout << endl;
}
int main() {
	cin >> T; getchar();
	string s;
	while (T--) {
		map<string, string> old;
		map<string, string> nova;
		for (int iii = 0; iii < 2; iii++) {
			getline(cin, s);

			//cout << s << endl;

			s = s.substr(1);
			while (s.length()) {
				string a, b;
				int mao = s.find(":");
				if (mao == -1) break;
				a = s.substr(0, mao);
				b = s.substr(mao + 1);
				int dou = b.find(",");
				if (dou == -1) dou = b.find("}");
				s = b.substr(dou + 1);
				b = b.substr(0, dou);
				
			//	cout << a << "   " << b << endl;
				if (iii == 0)  old[a] = b;
				else nova[a] = b;

			}
		}

		set<string>dele;
		set<string>add;
		set <string>change;

		for (map<string, string>::iterator o = old.begin(); o != old.end(); o++)
		{
			string oldKey = o->first, oldValue = o->second;
			if (!nova.count(oldKey)) dele.insert(oldKey);
			else {
				if (nova[oldKey] != oldValue) change.insert(oldKey);
			}
		}
		for (map<string, string>::iterator n = nova.begin(); n != nova.end(); n++) {

			string newKey = n->first, newValue = n->second;
			if (!old.count(newKey)) add.insert(newKey);
			
		}


		if (add.empty() && dele.empty() && change.empty())  cout << "No changes" << endl;
		
		if (!add.empty()) {
			print(add,"+");
		}

		if (!dele.empty()) {
			print(dele,"-");
		}

		if (!change.empty()) {
			bool first = true;
			print(change,"*");
		}

		cout << endl;


	}
}