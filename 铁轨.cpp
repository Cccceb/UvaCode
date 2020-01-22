#include<iostream>
#include<string>
#include<stack>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ìú¹ìin.txt", "r", stdin);
FILE *fout = freopen("Ìú¹ìout.txt", "w", stdout);
#endif 
using namespace std;
int target[1010];
int main() {
	int n;
	while (scanf("%d", &n) == 1&&n) {
		for (;;)
		{
			stack<int> C;
			int A = 1, B = 1;

			for (int i = 1; i <= n; i++) {
				scanf("%d", &target[i]);
				if (!target[i]) {
					cout << endl;
					goto here;
				}
			}
			bool ok = true;
			while (B <= n) {
				if (A == target[B]) { A++; B++; }
				else if (!C.empty() && C.top() == target[B]) {
					C.pop();
					B++;
				}
				else if (A <= n) C.push(A++);
				else {
					ok = false;
					break;
				}
			}
			ok ? cout << "Yes" << endl : cout << "No" << endl;
		}
	here:;

	}



}