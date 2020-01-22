#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("悲剧文本in.txt", "r", stdin);
FILE *fout = freopen("悲剧文本out.txt", "w", stdout);
#endif 
using namespace std;
#define maxn 100000+5
char s[maxn];
int main() {
	int  next[maxn];
	while (scanf("%s", s + 1) == 1)
	{

		next[0] = 0;
		int cur = 0, end = 0;
		for (int i = 1; i <= strlen(s+1); i++) {
			if (s[i] == ']') cur = end;
			else if (s[i] == '[') cur = 0;
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == end) end = i;
				cur = i;
			}

		}
		for (int i = next[0]; i ; i=next[i])
			printf("%c", s[i]);
		cout << endl;
	}

	

}