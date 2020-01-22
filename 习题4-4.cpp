#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚4-4in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚4-4out.txt", "w", stdout);
#endif 
using namespace std;
string s1, s2;
int cmp(string ans) {
	for (int i = 1; i < 3; i++) {
		if ((s1[i] != ans[i] || s1[5 - i] != ans[5 - i]))
			return 0;
	}
	return 1;
}
int main() {

	while (cin >> s1)
	{
		s2 = s1.substr(6.12);
		s1 = s1.substr(0, 6);
		string ans = s2;
		int flag = 0;
		for (int i = 0; i < 6; i++) {
			if (s2[i] == s1[0] && s2[5 - i] == s1[5]) {
				switch (i)
				{
				case 0: ans = s2; break;
				case 1: { ans[0] = s2[1]; ans[1] = s2[3]; ans[2] = s2[5]; ans[3] = s2[0]; ans[4] = s2[2]; ans[5] = s2[4]; break; }
				case 2:{ ans[0] = s2[2]; ans[1] = s2[1]; ans[2] = s2[5]; ans[3] = s2[0]; ans[4] = s2[4]; ans[5] = s2[3]; break; }
				case 5:{ ans[0] = s2[5]; ans[1] = s2[1]; ans[2] = s2[3]; ans[3] = s2[2]; ans[4] = s2[4]; ans[5] = s2[0];break;  }
				case 4:{ ans[0] = s2[4]; ans[1] = s2[3]; ans[2] = s2[0]; ans[3] = s2[5]; ans[4] = s2[2]; ans[5] = s2[1];break;  }
				case 3: { ans[0] = s2[3]; ans[1] = s2[1]; ans[2] = s2[0]; ans[3] = s2[5]; ans[4] = s2[4]; ans[5] = s2[2];break;  }
				}
					
				char tmp1 = ans[1];
				char tmp2 = ans[2];
				char tmp3 = ans[3];
				char tmp4 = ans[4];
				for (int j = 0; j < 4; j++)
				{
					switch (j) {
					case 0:if (cmp(ans)) flag = 1;  break;
					case 1:ans[1] = tmp2; ans[2] = tmp4; ans[3] = tmp1; ans[4] = tmp3; if (cmp(ans)) flag = 1;  break;
					case 2:ans[1] = tmp4; ans[2] = tmp3; ans[3] = tmp2; ans[4] = tmp1; if (cmp(ans)) flag = 1;  break;
					case 3:ans[1] = tmp3; ans[2] = tmp1; ans[3] = tmp4; ans[4] = tmp2; if (cmp(ans)) flag = 1; break;
					}
				}
			}

		}
		flag ? cout << "TRUE" << endl : cout << "FALSE" << endl;
	}

}

