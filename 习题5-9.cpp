#include<iostream>
#include<string>
#include<vector>
#include<map>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题5-9in.txt", "r", stdin);
FILE *fout = freopen("习题5-9out.txt", "w", stdout);
#endif 
using namespace std;
vector<string> off;
int  takeoff(string s) {
	off.clear();
	string a;
	string num;
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) a += s[i];
		else if (s[i] == '[') {
			off.push_back(a);
			a.clear();
		}
		else if (s[i] == ']') return atoi(num.c_str());
		else {
			num += s[i];
		}
	}
}
int main() {
	string s;
	for (;;) {
		int line = 0;
		map<string, map<long long,long long>> maxn;
		map<string, long long>lim;
		bool flag = true;
		while (getline(cin, s) && s != "."&&flag) {
			line++;
		//	cout << s << endl;
			int e = s.find('=');
			if (e ==-1) {//定义语句
				off.push_back(s.substr(0, s.find(']')));
				int m = takeoff(s);
				lim[off.front()] = m;
			}
			else {//赋值语句
				string le = s.substr(0, e );
				int l = takeoff(le);
				while (off.size() > 1) {
					if (!maxn[off.back()].count(l)) {
						flag = false;
					//	cout << "未初始化l1: " << line << endl;
						break;
					}
					l = maxn[off.back()][l];
					off.pop_back();
				}
				string ll = off.front();
				
			//	cout << "左式： " << ll << l << "  " << endl;

				if (l<0 || l>=lim[ll]) {
			//		cout << "越界l1:" << line << endl;
					flag = false;
					continue;
				}

				string ri = s.substr(e + 1) + "]";
				int r = takeoff(ri);
				while (off.size() > 1) {
					r = maxn[off.back()][r];
					off.pop_back();
				}
				string rr;
				if (!off.empty()) rr = off.front();
			//	cout << "右式： " << rr << r << "  "; maxn[rr].count(r) ? cout << maxn[rr][r] << endl : cout << endl;
				if (!rr.empty()) {
					if (r<0 || r>=lim[rr]) {
				//		cout << "越界r2:" << line << endl; 
						flag = false;
						break;;
					}
					if (!maxn[rr].count(r)) {
				//		cout << "未初始化r:" << line << endl;
						flag = false;
						break;;
					}

					maxn[ll][l] = maxn[rr][r];
				}
				else {
					maxn[ll][l] = r;
				}

		//	cout << "结果" <<ll<<l<<" = "<< maxn[ll][l] << endl;
			}
			
		}
		if (!flag) {
			cout << line << endl;
			while ( s != ".") getline(cin, s) ;
		}
		else cout << "0" << endl;
		if (cin.peek() == '.') return 0;
	}

}
