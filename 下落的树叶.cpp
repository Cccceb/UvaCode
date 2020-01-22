#include<iostream>
#include<string>
#include<map>
#include<iterator>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("下落的树叶in.txt", "r", stdin);
FILE *fout = freopen("下落的树叶out.txt", "w", stdout);
#endif 
using namespace std;
map<int, int> sum;
void build(int p) {
	int v;
	cin >> v;
	if (v == -1) return;
	sum[p] += v;
	build(p - 1);
	build(p + 1);
}
bool init() {
	int v;
	cin >> v;
	if (v == -1) return false;	
	sum.clear();
	int root = 0;
	sum[root] = v;
	build(root - 1);
	build(root + 1);
	return true;
}
int main() {
	int kase = 0;
	while (init()) {
		if (!sum.empty()) {
			map<int, int>::iterator p = sum.begin();
			cout << "Case " << ++kase << ":" << endl << (p++)->second;
			for (; p != sum.end(); p++) cout << " " << p->second;
		}
		cout << endl << endl;
	}
}