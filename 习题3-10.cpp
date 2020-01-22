#include<iostream>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题3-10in.txt", "r", stdin);
FILE *fout = freopen("习题3-10out.txt", "w", stdout);
#endif 
using namespace std;
int main() {
	for (;;) {
		int x[6][3]{};
		int mp[3][2]{};
		for (int i = 0; i < 6; i++)
		{
			int a, b;
			if (scanf("%d%d", &a, &b) != 2) return 0;
			if (a <0 || b<0) {
				return 0;
			}
			if (a > b) {
				x[i][0] = b;
				x[i][1] = a;
			}
			else {
				x[i][0] = a;
				x[i][1] = b;
			}

		}
			int cp = 1;
			for (int i = 0; i < 6; i++) {
				if (x[i][2] == 0) {

					for (int j = 0; j < 6; j++)
					{

						if (x[j][0] == x[i][0] && x[j][1] == x[i][1] && i != j && x[j][2] == 0) {
							mp[cp - 1][0] = x[j][0];
							mp[cp - 1][1] = x[j][1];
							x[j][2] = x[i][2] = cp++;

							break;
						}
					}

				}
			}
			if (cp == 4) {//cp==4表示可以配对
						//如果三对数可以首尾相接，那么可以构成长方体
				int flag = 0;
				for (int j = 0; j < 2; j++) {
					for (int i = 0; i < 2; i++) {
						if (mp[0][j] == mp[1][i]) {
							for (int k = 0; k < 2; k++) {
								if (mp[1][!i] == mp[2][k]) {
									if (mp[2][!k] == mp[0][!j])
									{
										flag = 1;
									}
								}
							}

						}
					}
				}
				flag ? cout << "POSSIBLE" <<endl: cout << "IMPOSSIBLE" << endl;

			}
			else cout << "IMPOSSIBLE" << endl;
	}


}