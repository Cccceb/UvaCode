#include<iostream>
#include<string>
#include<queue>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("Ê÷µÄ²ãÐò±éÀúin.txt", "r", stdin);
FILE *fout = freopen("Ê÷µÄ²ãÐò±éÀúout.txt", "w", stdout);
#endif 
using namespace std;
struct node {
	bool have_val;
	int v;
	node *le, *ri;
	node() :have_val(false), le(NULL), ri(NULL) {};
};
node* root;
node * newnode() {

	return new node();

}
bool flag;
void addnode(string s, int v) {
	node * u = root;
	for (int i = 0; i < s.length()-1; i++)
		if (s[i] == 'L') {
			if (u->le == NULL)
				u->le = newnode();
			u = u->le;

		}
		else if (s[i] == 'R') {
			if (u->ri == NULL)
				u->ri = newnode();
			u = u->ri;
		}
	if (u->have_val) {
		flag = false;
	}
	u->have_val = true;	
	u->v = v;


}
int main() {
	string s;
	
	while (cin.peek() != EOF&&cin.peek()!='\n') {
		root = newnode();

		flag = true;

		while (cin >> s && s != "()") {
			int v;
			sscanf(&s[1], "%d", &v);
			//		cout << v << endl;
			s = s.substr(s.find(',') + 1);
			addnode(s, v);
		}
		getchar();


		if (!flag) {
			cout << "not complete" << endl;
			continue;

		}
		node *tmp = root;
		queue<node *> travel;
		travel.push(tmp);
		string ans;
		while (!travel.empty()) {
			tmp= travel.front();
			travel.pop();
			
			if (!tmp->have_val) {
				flag = false;
				break;
			}
			ans =ans+" "+to_string( tmp->v);
			if (tmp->le) travel.push(tmp->le);
			if (tmp->ri) travel.push(tmp->ri);
		}

		flag ? cout << ans.substr(1) << endl : cout << "not complete" << endl;

	}

}