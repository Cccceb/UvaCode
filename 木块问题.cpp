/*
p110例5-2
*/
#include<iostream>
#include<string>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("木块问题in.txt", "r", stdin);
FILE *fout = freopen("木块问题out.txt", "w", stdout);
#endif 
using namespace std;
int n;
#define maxn 30//OJ中max已经被定义了,所以用上述方法或者const int maxn=30;
vector<int> p[maxn];
void find(int a, int &pa, int &h);
void clear_above(int a, int h);//把a堆高度为h的木块上方的所有木块归位
void pile_onto(int p, int h, int p2);//把p堆高度为h及其上方的木块整体移动到p2堆顶
void print();//输出各堆
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) p[i].push_back(i);
	string s1, s2;
	int a, b;
	while (cin >> s1 >> a >> s2 >> b) {
		int pa, pb, ha, hb;
		find(a, pa, ha);
		find(b, pb, hb);
		if (pa == pb) continue;//非法指令
		
		if (s1 == "move") clear_above(pa, ha);
		if (s2 == "onto") clear_above(pb, hb);
		pile_onto(pa, ha, pb);
	}
	print();
	return 0;
}
void find(int a, int &pa, int &h) {
	for (pa = 0; pa < n; pa++) {
		for (h = 0; h < p[pa].size(); h++) {
			if (p[pa][h] == a) return;
		}
	}
}
void clear_above(int a, int h) {
	//把a堆高度为h的木块上方的所有木块归位
	for (int i = h + 1; i < p[a].size(); i++) {
		p[p[a][i]].push_back(p[a][i]);
	}
	p[a].resize(h + 1);
}
void pile_onto(int p1, int h, int p2) {
	//把p堆高度为h及其上方的木块整体移动到p2堆顶
	for (int i = h; i < p[p1].size(); i++) {
		p[p2].push_back(p[p1][i]);
	}
	p[p1].resize(h);
}
void print(){
	//输出各堆
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < p[i].size(); j++) {
			cout << " " << p[i][j];
		}
		cout << endl;
	}
}