/*
p115例5-5
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
FILE *fin = freopen("集合栈计算机in.txt", "r", stdin);
FILE *fout = freopen("集合栈计算机out.txt", "w", stdout);
#endif 
using namespace std;
typedef set<int> Set;
map<Set, int> id;//将每个集合对应一个编号，编号是在向量中的下标
vector<Set> Setcache;
int ID(Set x) {//既是插入又是查询！！
	if (id.count(x)) return id[x];//存在则返回id

	//不存在则添加
	Setcache.push_back(x);
	return id[x] = Setcache.size() - 1;
}
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())//插入迭代器，插入而非覆盖https://blog.csdn.net/m0_37456764/article/details/83019250
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
			if (op[0] == 'P') s.push(ID(Set()));//空集入栈，注意此处空集的写法
			else if (op[0] == 'D') s.push(s.top());
			else {
				Set x1 = Setcache[s.top()]; s.pop();//因为pop的返回值为void
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

