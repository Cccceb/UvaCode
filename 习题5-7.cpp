
//list���ӡ������У�������ȼ�����pq�Ķ��ױ�list��˵�������л������ȼ����ߵ�������list�Ķ��׷��ڶ�β
//ֻ�е�pq�Ķ��׵���list�Ķ��׵�ʱ��list�������pq�ų���!!!
#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ϰ��5-7in.txt", "r", stdin);
FILE *fout = freopen("ϰ��5-7out.txt", "w", stdout);
#endif 
using namespace std;
int n;
struct node {
	int f;
	int pos;
	node(int f, int pos) :f(f), pos(pos) {}
};
int main() {
	cin >> n;
	while (n--)
	{
		queue<node> list;
		priority_queue<int> pq;
		int m, pos;
		cin >> m >> pos;


		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			pq.push(x);
			list.push(node(x,i));
		}
		
		int time = 0;
		while(!list.empty()&&!pq.empty()){
			if (list.front().f < pq.top()) {
				list.push(list.front());
				list.pop();
			}
			else if (list.front().f == pq.top()) {
				if (list.front().pos == pos) break;
				
					list.pop();
					pq.pop();
					time++;
				
			}

		}
		cout << time+1 << endl;
	}
}