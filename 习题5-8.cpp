#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("习题5-8in.txt", "r", stdin);
FILE *fout = freopen("习题5-8out.txt", "w", stdout);
#endif 
using namespace std;
string s;
struct node {
	string book;
	string auth;
	node() { }
	node(string book, string auth) : book(book), auth(auth) {}
	bool operator < (const node &a)const {
		return auth < a.auth || (auth == a.auth && book < a.book);
	}
};
int main() {
	set<node> library;
	map<string, string> who;
	set<node> after;
	while (getline(cin, s) && s != "END") {
		int f1 = s.find('"');
		int f2 = s.substr(f1+1).find('"');//+1!!!!
		node b(s.substr(f1 + 1, f2), s.substr(f2 + 5));
		library.insert(b);
		who[b.book] = b.auth;
	}



	while (getline(cin, s) && s != "END") {
		set<node>::iterator it;
		int f1 = s.find('"');
		int f2 = s.substr(f1 + 1).find('"');
		string bookname = s.substr(f1 + 1,f2);
		
		if (s[0] == 'B') {
			
			it = library.find(node(bookname, who[bookname]));
			
			if (it != library.end())	library.erase(it);
		}
		if (s[0] == 'R') {
			library.insert(node(bookname, who[bookname]));
			after.insert(node(bookname, who[bookname]));
		}
		if (s[0] == 'S') {

			

			for (set<node>::iterator i = after.begin(); i != after.end();i++) {//输出也是先按作者名排序再按书名排序
				bookname = i->book;
				it = library.find(node(bookname, who[bookname]));
				cout << "Put \"" << bookname <<"\"";
				if (it != library.begin()) cout << " after \"" << (--it)->book << "\""<<endl;
				else cout << " first" << endl;
			}
			cout << "END" << endl;
			after.clear();
		}
	}
}
