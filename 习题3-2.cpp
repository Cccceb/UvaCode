#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL

FILE *fin = freopen("习题3-2in.txt", "r", stdin);
FILE *fout = freopen("习题3-2out.txt", "w", stdout);
#endif 
double xigema(const char a, const int b);
int main() {
	using namespace std;
	int T;
	char s[105];
	cin >> T;
	while (T--) {
		double sum = 0;
		cin >> s;
		int mu;
		for (int i = 0; i < strlen(s); i++) {
			if (isalpha(s[i])) {
				//cout << s[i] << endl;
				//cout << s[i + 1] << endl;
				if (isalpha(s[i + 1]) || s[i + 1] == '\0') {
					sum += xigema(s[i], 1);

				}
				else if (s[i + 1] <= '9'&&s[i + 1] >= '1') {//下一位为数字
					int j = i;
					mu = 0;
					while ('1' <= s[i + 1] && s[i + 1] <= '9') {//一定要写等号！！！！
																//一定要用&&相连接！！！
						mu = (int(s[i + 1] - '0') + mu * 10);
						i++;
					}
					sum += xigema(s[j], mu);
					//cout <<"sum: "<< sum << endl;
				}


			}
		}
		printf("%.3f\n", sum);
	}
}
double xigema(const char a, const int n) {
	//cout << "n = " << n << endl;
	switch (a) {
	case 'C':return 12.01*n;
	case 'H':return 1.008*n;
	case 'O':return 16.00*n;
	case 'N':return 14.01*n;
	defult:return 0.0;
	}
}