#include<iostream>
#include<cstring>
#define LOCAL
#pragma warning (disable: 4996)
using namespace std;
int main() {
#ifdef LOCAL
	FILE *fin, *fout;
	fin = freopen("习题3-1in.txt", "r", stdin);
	fout = freopen("习题3-1out.txt", "w", stdout);
#endif 
	char s[85];
	int n,sum;
	scanf("%d", &n);
	while (n--) {
		sum = 0;
		int p = 0;//p存O的分
		scanf("%s", s);
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'O') {
				p++;
				sum += p;
			}
			else if (s[i] == 'X') {
				p = 0;
				sum += 0;
			}
		}		
		std::cout << sum << std::endl;
	}
	
}