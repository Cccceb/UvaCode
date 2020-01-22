/*
刽子手游戏是一款简单的猜词游戏，规则是计算机想一个单词让你猜，你每次可以
猜一个字母。如果单词里有那个字母，则计算机会在一幅“刽子手”画上填上一笔。
这幅画一共需要七笔就能完成，因此你最多只能错6次。注意，猜一个已经猜过的字母
也算错，本题中，你的任务是编写一个裁判程序，输入单词和玩家的猜测，判断玩家赢了
、输了、放弃了。每组数据包含3行，第一行是游戏编号(-1为输入结束标记)，第二行是计算
机想的单词，第三行是玩家的猜测。后面两行保证只有小写字母	
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("刽子手in.txt", "r", stdin);
FILE *fout = freopen("刽子手out.txt", "w", stdout);
#endif 
int main() {
	using namespace std;
	int n, first = 1;
	while (cin >> n && n != -1) {
		cout << "Round " << n << endl;
		char ans[10000]{}; 
		int A = 0;
		int a[26]{};
		char c;
		getchar();
		while ((c=getchar())!='\n') {
			//cout << "c: " << c <<c-'a'<< endl;
			if (a[c - 'a'] == 0) {
				a[c - 'a'] = 1;
				A++;
			}	
		}
		//for (int i = 0; i < 26; i++) cout << a[i] << " ";cout << endl;
		int num = 0;
		scanf("%s", ans);	
		int j = 0,B=0;//A记录答案序列中出现的不同字母个数
					//B记录猜测序列中猜对的字母个数
		while ((c=ans[j++])!='\0'&&num<7) {
			//cout << c ;
			if (a[c - 'a'] == 1) {
				a[c - 'a'] = 0;
				B++;
				if (B == A) {
					num = -10000;//如果已经猜对了，即使后面错够了7个也不算
				}
			}
			else num++;
		}
		/*cout << "A: " << A << " B: " << B<<endl;
		for (int i = 0; i < 26; i++) cout << a[i] << " " ;cout << endl;
		cout << "num : " << num << endl;;*/
		int flag = 1;
		if (num == 7) flag = 0;
		else{
			for (int i = 0; i < 26; i++) {
				if (a[i] == 1) flag = 2;
			}
		}
		if (flag == 1) cout << "You win.";
		if (flag == 0) cout << "You lose.";
		if (flag == 2)   cout << "You chickened out.";
		/*if (first) first = 0;
		else */
			cout << endl;
	}
}