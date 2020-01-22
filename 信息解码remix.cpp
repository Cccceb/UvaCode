#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("信息解码in.txt", "r", stdin);
FILE *fout = freopen("信息解码out.txt", "w", stdout);
#endif 
using namespace std;
map<int, string> head;
int to_ten(string s) {
	int ans = 0;
	for (int i = 0; i < s.length(); i++) 
		ans = 2 * ans + s[i] - '0';
	return ans;
}
int main() {
	string h;
	while (getline(cin, h)) {
		for (int i = 0; i < h.length(); i++)
			head[i] = h[i];
		string line;
		int first = 1;
		bool flag = false;
		int m = 0;
		while (getline(cin, line)) {
			if (line.substr(line.length() - 4, 3) == "000") {
				line = line.substr(0, line.length() - 3);
				flag = true;;
			}
			
			if (first) {
				string sp = line.substr(0, 3);
				first = 0;
				m = to_ten(sp);
				line = line.substr(3);
			}
		
			for (int i = 0; i < line.length(); i =i+ m) {
				cout << head[to_ten(line.substr(i, m))];
			}



			if (flag) break;
			

		}
		
	}
}