#define LOCAL
#ifdef LOCAL
#pragma  warning (disable:4996) 
#endif
#include<iostream>
int main() {
	using namespace std;
	int n;
	int i, j, k;
	scanf("%d", &n);
	for (i = n; i >= 1; i--) {
		for (j = 0; j <n-i; j++) {
			printf(" ");
		}
		for (k = 1; k <=2 * i - 1; k++) {
			printf("#");
		}
		cout << endl;
	}
	system("pause");
}