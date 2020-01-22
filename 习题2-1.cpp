#include<iostream>
int main() {
	int i, j, k;
	for (i = 1; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 9; k++) {
				if((i*100+j*10+k)==(pow(i,3)+pow(j,3)+pow(k,3)))
				printf("%d ", (i * 100 + j * 10 + k));
			}
		}
	}
	system("pause");
}