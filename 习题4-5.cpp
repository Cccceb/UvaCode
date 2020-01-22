#include<iostream>
#include<string.h>
#include<string>
#include <algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题4-5in.txt", "r", stdin);
FILE *fout = freopen("习题4-5out.txt", "w", stdout);
#endif 
using namespace std;
string turn(int a);
int turnback(string a);
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		//cout << "n:  " << n << endl;
		string b[1000]{};
		int r = 0;
		int t = n;
		while (n--) {

			int a;
			for (int i = 0; i < 4; i++) {
				cin >> a;
				getchar();
				b[r] += turn(a);
			}
			r++;
		}


		int num = 32;
		string ans;
		int flag=1;
		if (t == 1) ans = b[0];
		else {
			for (int k = 0; k < 32; k++) {
				for (int j = 1; j < r; j++)
					if (b[0][k] != b[j][k]) {
						num = k;
						flag = 0;
						goto here;
					}
					if(flag) ans += b[0][k];
			}
		}
	here:;
			//补齐位数
			while (ans.length() < 32) ans +="0";
	


		//	cout << "ans:  " <<ans.length()<<"  "<< ans << endl;

			//输出最小网络
			int first = 1;
			for (int k = 0; k < 4; k++) {
				string s;
				for (int j = 0; j < 8; j++) {
					s += ans[j + 8 * k];
				}
			
				if (first) first = 0; else { cout << "."; } cout <<turnback(s) ;
			}
			cout << endl;

			//输出子网掩码
			 string subnet;
			for (int i = 0; i < 32; i++) {
				if (i < num) subnet += "1";
				else subnet += "0";
			}


			first = 1;
			for (int k = 0; k < 4; k++) {
				string s;
				for (int j = 0; j < 8; j++) {
					s += subnet[j + 8 * k];
				}

				if (first) first = 0; else { cout << "."; } cout << turnback(s);
			}
			cout << endl;
	}

	

}
string turn(int a) {
	string b;
	for (int i = 0; i < 8; i++) {
		b += (char)(a % 2 + '0');

		a /= 2;
	}
	reverse(b.begin(), b.end());
	return b;
}
int turnback(string a) {
	
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += (a[i] - '0');
		sum *= 2;
	}
	return sum/2;
}