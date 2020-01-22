/*
p115��5-5
*/
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<iterator>
#include<algorithm>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("����ջ�����in.txt", "r", stdin);
FILE *fout = freopen("����ջ�����out.txt", "w", stdout);
#endif 
using namespace std;
typedef set<int> Set;
map<Set, int> id;//��ÿ�����϶�Ӧһ����ţ�������������е��±�
vector<Set> Setcache;
int ID(Set x) {//���ǲ������ǲ�ѯ����
	if (id.count(x)) return id[x];//�����򷵻�id

	//�����������
	Setcache.push_back(x);
	return id[x] = Setcache.size() - 1;
}
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())//�����������������Ǹ���https://blog.csdn.net/m0_37456764/article/details/83019250
int main() {
	int n;
	
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		stack<int> s;
		while (m--) {
			string op;
			cin >> op;
			if (op[0] == 'P') s.push(ID(Set()));//�ռ���ջ��ע��˴��ռ���д��
			else if (op[0] == 'D') s.push(s.top());
			else {
				Set x1 = Setcache[s.top()]; s.pop();//��Ϊpop�ķ���ֵΪvoid
				Set x2 = Setcache[s.top()]; s.pop();
				Set x;
				if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
				s.push(ID(x));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
}

