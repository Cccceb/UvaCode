#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚3-5in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚3-5out.txt", "w", stdout);
#endif 
#define lr 5
#define maxn 1000
char s[5][5];//¥Êæÿ’Û
int move(int a, int b);
int x, y;
int main() {
	using namespace std;
	int kase = 0,first=1;
	
	for (;;)
	{
		bool flag = true;
		for (int i = 0; i < lr; i++) {
			for (int j = 0; j < lr; j++) {
				s[i][j] = getchar();
				if (s[i][j] == ' ') {
					x = i;
					y = j;
				}
			}
			getchar();
		}
		//cout << "x: " << x << "y: " << y << endl;
		if (first) first = 0;
		else  printf("\n"); 
		cout << "Puzzle #" << ++kase << ":" << endl;
		char ord;
		while (scanf("%c", &ord) && (ord != '0')) {
				//cout <<"ord:  "<< ord <<endl;
			switch (ord) {
			case 'L':move(x, y - 1)&& flag ? flag = true : flag = false; break;
			case 'R':move(x, y + 1)&& flag ? flag = true : flag = false; break;
			case 'A':move(x - 1, y)&& flag ? flag = true : flag = false; break;
			case 'B':move(x + 1, y)&& flag ? flag = true : flag = false; break;
			case '\n':break;
			default:flag = false;
			}
		
		}
			//cout << "flag: " << flag << endl;
		if (flag) {
			for (int i = 0; i < lr; i++) {
				for (int j = 0; j < lr; j++) {
					printf("%c", s[i][j]);
					if (j)
					{
						if(j % (lr - 1) == 0) cout << endl;
						else if (j)cout << " ";
					}
					else cout << " ";
					
				}
			}
		}
		else {
			cout << "This puzzle has no final configuration." << endl;
		}
		char c;
		c = getchar();
		if (cin.peek() == 'Z') {
			//cout << "ZZZZZZZ" << endl;
			return 0;
		}
	}

}
int move(int a, int b) {
	using namespace std;
	//cout << "a : " << a << "b : " << b << endl;
	if (a>=0 && a < lr && b>=0 && b < lr) {
		s[x][y] = s[a][b];
		s[a][b] = ' ';
		x = a;
		y = b;
		return 1;
	}
	else return 0;

}