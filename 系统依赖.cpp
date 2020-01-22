#include<iostream>
#include<list>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("系统依赖in.txt", "r", stdin);
FILE *fout = freopen("系统依赖out.txt", "w", stdout);
#endif 
using namespace std;
map<string, vector<string>> depend;
map<string, int> install;
list<string> li;
void ins(string name) {

	for (int i = 0; i < depend[name].size(); i++) {
		string dep = depend[name][i];

		if (!depend[dep].empty())
			ins(dep);

		if (!install[dep])
		{
			cout << "   Installing " << dep << endl;
			li.push_back(dep);
		

		}
		install[dep]++;
	}
	if (!install[name])
	{
		cout << "   Installing " << name << endl;
		li.push_back(name);
	

	}
	install[name]++;

}
void remove(string name) {
	install[name]--;
	if (!install[name])
	{
		cout << "   Removing " << name << endl;
		install.erase(name);
		auto it = find(li.begin(), li.end(), name);
		li.erase(it);
	}
	for (int i = 0; i < depend[name].size(); i++) {
		string dep = depend[name][i];
		install[dep]--;
		if (!install[dep])
		{
			cout << "   Removing " << dep << endl;
			install.erase(dep);
			auto it = find(li.begin(), li.end(), dep);
			li.erase(it);
		}
		if (!depend[dep].empty())
			remove(dep);


	}



}
int main()
{
	string order;
	while (getline(cin, order) ) {
		cout << order << endl;
		stringstream ss(order);
		if (order[0] == 'D') {
			order = order.substr(order.find(' ') + 1);
			stringstream ss(order);
			int first = 1;
			string name, s;
			while (ss >> s) {
				if (first) {
					name = s;
					first = 0;
				}
				else depend[name].push_back(s);
			}

		}




		else if (order[0] == 'I') {

			ss >> order>>order;
			if (install[order]) {
				cout << "   " << order << " is already installed." << endl;;
				continue;;
			}
			ins(order);

		}
		else if (order[0] == 'R') {
			ss >> order>>order;
			if (install[order]>1) {
				cout << "   " << order << " is still needed." << endl;
				continue;
			}
			if (!install[order]) {
				cout << "   " << order << " is not installed." << endl;
				continue;
			}
			remove(order);
		}

		else if (order[0] == 'L') {
			for (auto it = li.begin(); it != li.end(); it++)
				cout << "   "<<*it << endl;
		}
	}
}
