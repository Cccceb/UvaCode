/*
p130 例5-11 uva814
*/
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("邮件传输代理in.txt", "r", stdin);
FILE *fout = freopen("邮件传输代理out.txt", "w", stdout);
#endif 
using namespace std;

void pare_address(const string s, string &user, string &mta) {
	int k = s.find('@');
	user = s.substr(0, k);
	mta = s.substr(k + 1);
}

int main()
{
	string s;
	set<string> addr;//存每个mta对应用户的列表

	string user1, mta1;
	while (cin >> s && s != "*") {
		int k;
		string loc;
		cin >> s >> k;
		while (k--) {
			cin >> loc;
			addr.insert(loc + "@" + s);
		}
	}//输入完成
	string sender;
	while (cin >> sender && sender != "*") {

		pare_address(sender, user1, mta1);
		vector<string> mta;//按序存目的地址
		map<string, vector<string>> dest;//存每个mta要发送的用户
		set<string> vis;

		while (cin >> s && s != "*") {
			string user2, mta2;
			pare_address(s, user2, mta2);

			if (vis.count(s)) continue;//重复收件人
			vis.insert(s);
			if (!dest.count(mta2)) {
				mta.push_back(mta2);
				dest[mta2] = vector<string>();
			}
			dest[mta2].push_back(s);
		}





		/*for (int i = 0; i < mta.size(); i++) cout << i << " " << mta[i] << endl;
		for (map<string, vector<string>>::iterator it = dest.begin(); it != dest.end(); it++)
			for (int i = 0; i < it->second.size(); i++)
				cout << it->second[i] << endl;*/


		getline(cin, s);
		//输入正文
		string data;
		while (getline(cin, s) && s[0] != '*')	data += "     " + s + "\n";

		for (int i = 0; i < mta.size(); i++) {
			string mta2 = mta[i];

			cout << "Connection between " << mta1 << " and " << mta2 << endl;
			cout << "     HELO " << mta1 << endl << "     250\n";
			cout << "     MAIL FROM:<" << sender << ">" << endl << "     250" << endl;

			vector<string> users = dest[mta2];

			bool ok = false;
			for (int j = 0; j < users.size(); j++) {
				cout << "     RCPT TO:<" << users[j] << ">" << endl;
				if (addr.count(users[j])) {
					ok = true;
					cout << "     250" << endl;
				}
				else {
					cout << "     550" << endl;
				}
			}
			if (ok) {
				cout << "     DATA" << endl << "     354" << endl;
				cout << data << "     ." << endl << "     250" << endl;
			}



			cout << "     QUIT" << endl << "     221" << endl;
		}

	}
}