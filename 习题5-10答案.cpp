//{头文件模板
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
FILE *fin = freopen("习题5-10in.txt", "r", stdin);
FILE *fout = freopen("习题5-10out.txt", "w", stdout);
#endif 
using namespace std;
//}头文件模板
#define rep(i,b) for(int i=0; i<(b); i++)
#define foreach(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
#define FOR for (int j = limit[i]; j < limit[i + 1]; j++)
typedef bool Bit[1505];

int n, lines, m;          // n文档数, lines行数, m请求数
int limit[105];           // limit[i]: 第i篇文档从第几行开始

string doc[1505];         // 存储内容
map<string, Bit> Index;   // Index[单词]: B标记了哪些行出现过

// 用s来更新Index
void upDate(string s, int p) {
	string word;
	foreach(it, s) {
		if (isalpha(*it)) *it = tolower(*it); // 变小写
		else *it = ' '; // 非字母变空白
	}

	stringstream ss2(s);
	while (ss2 >> word) Index[word][p] = true;
}

int main() {
	//{section: 文档数据输入
	scanf("%d ", &n);
	rep(i, n) {
		limit[i] = lines;
		while (getline(cin, doc[lines]), doc[lines] != "**********") {
			upDate(doc[lines], lines);
			lines++;
		}
	}
	limit[n] = lines;//}

	//{section: 对获取的请求输出对应的内容
	string  s;                      // s存储每次得到的请求
	Bit     mark;                   //{记录哪些行应该输出
									//}mark的解释: 因为每篇文档要用10个'-'隔开,比较麻烦,最后统一处理
	bool    *A, *B;

	scanf("%d ", &m);
	for (int iii = 0; iii < m; iii++) {
		getline(cin, s);

		//{subsection: 计算出mark中介
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
			bool hasA, hasB;    // 在同一文章中, 两个词是否都出现
			rep(i, n) {
				hasA = hasB = false;    // 默认没出现
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

	 //{subsection: 输出mark
		bool hasOut = false, needOut = false;    // 记录上一轮是否有输出文档
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