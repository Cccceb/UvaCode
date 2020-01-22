#include<iostream>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("四分树in.txt", "r", stdin);
FILE *fout = freopen("四分树out.txt", "w", stdout);
#endif 
using namespace std;
const int len = 32;
string p;
int buf[len][len], cnt;
void draw(int x, int y, int w, int &pos) {
	char c = p[pos++]; 

	if (c == 'p') {
		draw(x + w / 2, y, w / 2, pos);//1
		draw(x, y, w / 2, pos);//2
		draw(x, y + w / 2, w / 2, pos);//3
		draw(x + w / 2, y + w / 2, w / 2, pos);//4
	}
	else if (c == 'f') {
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + w; j++) {
				if (buf[i][j] == 0) {
					buf[i][j] = 1;
					cnt++;
				}
			}
		}
	}

}
int main() {
	int T;
	cin >> T; getchar();
	while (T--)
	{

		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for (int i = 0; i < 2; i++) {
			getline(cin, p);
			int pos = 0;
			draw(0, 0, len, pos);
		}

		cout << "There are "<<cnt<<" black pixels." << endl;
	}
}