//{ͷ�ļ�ģ��
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("ϰ��5-10in.txt", "r", stdin);
FILE *fout = freopen("ϰ��5-10out.txt", "w", stdout);
#endif 
using namespace std;
//}ͷ�ļ�ģ��
#define rep(i,b) for(int i=0; i<(b); i++)
#define foreach(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
#define FOR for (int j = limit[i]; j < limit[i + 1]; j++)
typedef bool Bit[1505];

int n, lines, m;          // n�ĵ���, lines����, m������
int limit[105];           // limit[i]: ��iƪ�ĵ��ӵڼ��п�ʼ

string doc[1505];         // �洢����
map<string, Bit> Index;   // Index[����]: B�������Щ�г��ֹ�

// ��s������Index
void upDate(string s, int p) {
	string word;
	foreach(it, s) {
		if (isalpha(*it)) *it = tolower(*it); // ��Сд
		else *it = ' '; // ����ĸ��հ�
	}

	stringstream ss2(s);
	while (ss2 >> word) Index[word][p] = true;
}

int main() {
	//{section: �ĵ���������
	scanf("%d ", &n);
	rep(i, n) {
		limit[i] = lines;
		while (getline(cin, doc[lines]), doc[lines] != "**********") {
			upDate(doc[lines], lines);
			lines++;
		}
	}
	limit[n] = lines;//}

	//{section: �Ի�ȡ�����������Ӧ������
	string  s;                      // s�洢ÿ�εõ�������
	Bit     mark;                   //{��¼��Щ��Ӧ�����
									//}mark�Ľ���: ��Ϊÿƪ�ĵ�Ҫ��10��'-'����,�Ƚ��鷳,���ͳһ����
	bool    *A, *B;

	scanf("%d ", &m);
	for (int iii = 0; iii < m; iii++) {
		getline(cin, s);

		//{subsection: �����mark�н�
		if (s[0] == 'N') {
			A = Index[s.substr(4)];
			rep(i, n) {
				bool logo = true;
				FOR if (A[j]) { logo = false; break; }
				FOR mark[j] = logo;
			}
		}
		else if (s.find("AND") != string::npos) {
			int p = s.find(" AND ");
			A = Index[s.substr(0, p)];
			B = Index[s.substr(p + 5)];
			memset(mark, 0, sizeof(mark));
			bool hasA, hasB;    // ��ͬһ������, �������Ƿ񶼳���
			rep(i, n) {
				hasA = hasB = false;    // Ĭ��û����
				FOR if (A[j]) { hasA = true; break; }
				FOR if (B[j]) { hasB = true; break; }
				if (!(hasA&&hasB)) continue;
				FOR mark[j] = (A[j] || B[j]);
			}
		}
		else if (s.find("OR") != string::npos) {
			int p = s.find(" OR ");
			A = Index[s.substr(0, p)];
			B = Index[s.substr(p + 4)];
			rep(i, lines) mark[i] = (A[i] || B[i]);
		}
		else memcpy(mark, Index[s], sizeof(mark));//}

	 //{subsection: ���mark
		bool hasOut = false, needOut = false;    // ��¼��һ���Ƿ�������ĵ�
		rep(i, n) {
			if (hasOut) needOut = true;
			hasOut = false;
			FOR if (mark[j]) {
				if (needOut) {
					cout << "----------\n";
					needOut = false;
				}
				cout << doc[j] << "\n";
				hasOut = true;
			}
		}
		if (!(needOut || hasOut)) cout << "Sorry, I found nothing.\n";
		cout << "==========\n";//}
	}//}

	return 0;
}