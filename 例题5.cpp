#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����5in.txt", "r", stdin);
FILE *fout = freopen("����5out.txt", "w", stdout);
#endif
using namespace std;
int L, T, n;
const int maxn = 10005;
struct Node {
	int x, dir, id;
	Node() {}
	Node(int id, int x, int dir) :id(id), x(x), dir(dir) {}
	bool operator < (const Node&a) const { return x < a.x; }
}before[maxn],after[maxn];
bool cmp(const Node&a,const Node&b){return a.id<b.id;}
int order[maxn];
const string dirname[] = { "L","Turning","R" };
int main() {
	ios::sync_with_stdio(false);
	//������ײ�ͺ��񴩹�ȥһ��
	int K;
	cin >> K;
	for (int kase = 1; kase <= K; kase++)
	{
		cin >> L >> T >> n;
		memset(order, 0, sizeof(order));
		memset(before, 0, sizeof(before));
		memset(after, 0, sizeof(after));
		cout << "Case #" << kase << ":" << endl;
		for (int i = 0; i < n; i++) {
			int x; char dir;
			cin >> x >> dir;
			int d = (dir == 'L' ? -1 : 1);
			before[i] = Node(i, x, d);
			after[i] = Node(0, x+T*d, d);
		}
		
		sort(before,before+n);
		for (int i = 0; i < n; i++)
			order[before[i].id] =i;//������ײ�ͻᷴ���������ϵ����λ���ǲ���ġ�
								//Ҳ����˵��Ҫȷ������˳���еĵ�iֻ����һ��������
								//���Խ��������ӳ�䵽һ���������ϣ���ʹ�˶�Ҳ����ı�

		sort(after,after+n);
		for (int i = 0; i < n - 1; i++)
			if (after[i].x == after[i + 1].x) after[i].dir = after[i + 1].dir = 0;

		
		for (int i = 0; i < n; i++) {
			int a = order[i];
			if (after[a].x < 0 || after[a].x>L) cout << "Fell off" << endl;
			else 
				cout << after[a].x << " " << dirname[after[a].dir + 1] << endl;
		}
		cout << endl;
	}

}