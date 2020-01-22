#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
#define maxn 10000
FILE *fin = freopen("刽子手in.txt", "r", stdin);
FILE *fout = freopen("刽子手out.txt", "w", stdout);
#endif
#define maxn 100
int le, chance;
char s[maxn], s2[maxn];
int win, lose;
void guess(char c);
int main() {
	int rnd;
	while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1) {
		printf("Round %d\n", rnd); 
			win = lose = 0;
		le = strlen(s);
		chance = 7;
		for (int i = 0; i < strlen(s2); i++) {
			guess(s2[i]);
			if (win || lose) break;
		}
		if (win) printf("You win.\n");
		else if (lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}
void guess(char c) {
	int bad = 1;
	for(int i=0;i<strlen(s);i++){
		if (s[i] == c) {
			le--;
			s[i] = ' ';
			bad = 0;
		}
	}
	if (bad) --chance;
	if (!chance) lose = 1;
	if (!le) win = 1;
}