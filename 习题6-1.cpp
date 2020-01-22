#include<iostream>
#include<string>
#include<stack>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题6-1in.txt", "r", stdin);
FILE *fout = freopen("习题6-1out.txt", "w", stdout);
#endif 
using namespace std;
int n,len,j;
int main() {
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (s.empty()) {//空串合法
			printf("Yes\n");
			continue;
		}
		stack<char> sk;
		len= s.length();
		j=0;
		while (j < len) {
			if (s[j] == '[' || s[j] == '(') sk.push(s[j]);
			else {
				char ch;
				if (sk.empty())	break;
				ch = sk.top(); sk.pop();
				if ((s[j] == ']'&&ch != '[') || (s[j] == ')'&&ch != '(')) {
					break;
				}
			}
			j++;
		} 
		if (j == len&&sk.empty()) printf("Yes\n");
		else printf("No\n");
	}
}