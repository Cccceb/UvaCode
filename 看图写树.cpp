#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("¿´Í¼Ð´Ê÷in.txt", "r", stdin);
FILE *fout = freopen("¿´Í¼Ð´Ê÷out.txt", "w", stdout);
#endif 
using namespace std;
vector<string> buf;
set<char> ob;
map<int, map<int, int>> have;
void travel(int r, int i) {
	
	int c = i;
	if (r >= buf.size()-1 || c >= buf[r].size()) return;
	cout << buf[r][c] << "(";
	if (r+1<buf.size()&&c<buf[r+1].size()&&buf[r + 1][c] == '|') {
		while (c - 1 >= 0 && buf[r + 2][c - 1] == '-') c--;//ÕÒµ½×ó¶Ë
		while (c < buf[r + 2].size()&&buf[r + 2][c] == '-') {
			if (!isspace(buf[r+3][c]) && !ob.count(buf[r+3][c])) travel(r + 3, c);
			c++;
		}
	}
	cout << ")";
}
int main() {
	int T;
	cin >> T; getchar();
	
	ob.insert('#');
	ob.insert('-');
	ob.insert('|');
	while (T--) {
		string s;
		have.clear();
		buf.clear();
		while (getline(cin, s)) {
			buf.push_back(s);
			if (s == "#") break;
		}
		
		cout << "(";
		int i = 0;
			for (int j = 0; j < buf[0].size(); j++)
				if (!isspace(buf[i][j])&&!ob.count(buf[i][j])) 	
					travel(0, j);
		cout << ")" << endl;
	}

}