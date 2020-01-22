#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("例题3in.txt", "r", stdin);
FILE *fout = freopen("例题3out.txt", "w", stdout);
#endif
using namespace std; 
const int maxn = 1000000 + 10;

int main() {
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		long long sum = 0;
		long long in[maxn], have[maxn];
		if (!n) {
			cout << "0" << endl;
			continue;
		}
		
		for (int i =1; i <= n; i++) {

			cin >> in[i];
			sum += in[i];
			
			
		}
		long long mid = sum / n;
		
		have[0] = 0;
		for (int i = 1; i <n; i++) {
			have[i] =have[i-1] + in[i] - mid;//递推得到have数组，具体分析见P5
		}
		sort(have, have+n);
	
		
		long long x1 = have[n / 2], ex = 0;
		for (int i = 0; i < n; i++) {
			ex += abs(have[i] - x1);
		}
		cout << ex << endl;
	}
}