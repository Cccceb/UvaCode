#include<iostream>
#include<map>
#include<string>
#include<stack>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("¾ØÕóÁ´³Ëin.txt", "r", stdin);
FILE *fout = freopen("¾ØÕóÁ´³Ëout.txt", "w", stdout);
#endif // LOCAL
using namespace std;
struct node {
	int r;
	int c;
	node(int r = 0, int c = 0) : r(r), c(c) {}
}place[26];
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		char c;
		cin >> c >> x >> y;
		place[c - 'A'] = node(x, y);
	}
	getchar();
		
		string s;
		while (getline(cin, s)) {
			stack<node> op;
			int sum = 0;
			for (int i = 0; i < s.length(); i++) {
				if (isalpha(s[i])) op.push(place[s[i] - 'A']);
				else if (s[i] == ')') {
					node a = op.top(); op.pop();
					node b = op.top(); op.pop();
					if (b.c != a.r) {
						cout << "error" << endl;
						break;
					}
					else {
						sum += b.r*b.c*a.c;
						op.push(node(b.r, a.c));
					}
				}
				if (i == s.length() - 1) cout << sum << endl;
			}

		}

	

}