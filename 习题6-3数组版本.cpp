#include<iostream>
#include<string>
#include<sstream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题6-3in.txt", "r", stdin);
FILE *fout = freopen("习题6-3out.txt", "w", stdout);
#endif 
using namespace std;
const int maxn = 30;
int n;
string in;
char pre_order[maxn], in_order[maxn];
int lch[maxn], rch[maxn];
int createTree(int l1, int r1, int l2, int r2) {
	if (l2 > r2) return 0;//空树


	char root = pre_order[l1];
	int p = l2;
	while (in_order[p] != root) p++;
	int k = p - l2;//左子树节点数

	lch[l1] = createTree(l1 + 1, l1 + k, l2,l2+k - 1);
	rch[l1] = createTree(l1 + k + 1, r1, l2+k+1, r2);
	return l1;
}
void post_order(int index) {
	if (pre_order[index]==-1) return ;
	if(lch[index]) post_order(lch[index]);
	if(rch[index]) post_order(rch[index]);
	cout << pre_order[index];
	return;
}
void read_lines(char *a) {
	stringstream ss(in);
	n = 0;
	char ch;
	while (ss >> ch) a[n++] = ch;
}
int main() {

	while (cin >> in) {
		memset(pre_order, -1, sizeof(pre_order));
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		read_lines(pre_order);
		cin >> in;
		read_lines(in_order);

		createTree(0, n - 1, 0, n - 1);
		post_order(0);
		cout << endl;
	}
}