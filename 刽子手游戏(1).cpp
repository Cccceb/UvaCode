/*
��������Ϸ��һ��򵥵Ĳ´���Ϸ�������Ǽ������һ����������£���ÿ�ο���
��һ����ĸ��������������Ǹ���ĸ������������һ���������֡���������һ�ʡ�
�����һ����Ҫ�߱ʾ�����ɣ���������ֻ�ܴ�6�Ρ�ע�⣬��һ���Ѿ��¹�����ĸ
Ҳ��������У���������Ǳ�дһ�����г������뵥�ʺ���ҵĲ²⣬�ж����Ӯ��
�����ˡ������ˡ�ÿ�����ݰ���3�У���һ������Ϸ���(-1Ϊ����������)���ڶ����Ǽ���
����ĵ��ʣ�����������ҵĲ²⡣�������б�ֻ֤��Сд��ĸ	
*/
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("������in.txt", "r", stdin);
FILE *fout = freopen("������out.txt", "w", stdout);
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
		int j = 0,B=0;//A��¼�������г��ֵĲ�ͬ��ĸ����
					//B��¼�²������в¶Ե���ĸ����
		while ((c=ans[j++])!='\0'&&num<7) {
			//cout << c ;
			if (a[c - 'a'] == 1) {
				a[c - 'a'] = 0;
				B++;
				if (B == A) {
					num = -10000;//����Ѿ��¶��ˣ���ʹ�������7��Ҳ����
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