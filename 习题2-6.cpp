#pragma warning (disable:4996)
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int a[] = { 1,2,3,4,5,6,7,8,9 };
bool can(int i);
bool judge(int sum);
int main() {
	int i, j, k;
	for (i = 123; i < 329; i++) {
		j = 2 * i;
		k = 3 * i;
		if (judge(i) && judge(j) && judge(k)) {
			cout << i << " " << j << " " << k << " " << endl;
		}
		for (int t = 0; t < 9; t++) {
			a[t] = t + 1;
		}
	}
	system("pause");

}
bool can(int val) {
	for (int &i : a)
		if (i == val) {
			i = -1;
			return true;
		}
	return false;
}
bool judge(int sum) {
	if (can(sum / 100) && can(sum / 10 % 10) && can(sum % 10)) return true;
	else return false;
}