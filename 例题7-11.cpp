#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
FILE *fin = freopen("����7-11in.txt", "r", stdin);
FILE *fout = freopen("����7-11out.txt", "w", stdout);
typedef long long int64;
using std::swap; using std::max;
int main() {
	int T, id = 0; scanf("%d", &T);
	while (T--) {
		int n, s1, v1, s2, v2; scanf("%d %d %d %d %d", &n, &s1, &v1, &s2, &v2);
		if (s1 > s2) swap(s1, s2), swap(v1, v2);//Ŀ����ʹ��S2>S1
		int64 ans = 0;
		if (n / s2 >= 65536) {	//S2>S1���������S2������65536��˵��S2�ͺ�С����ôS1��С����ôʹ������ö�١�
			for (int64 i = 0; i <= s1; i++) ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
			for (int64 i = 0; i <= s2; i++) ans = max(ans, v1 * i + (n - s1 * i) / s2 * v2);
		}
		else {//����ö�ٱ���2��������
			for (int64 i = 0; s2 * i <= n; i++) ans = max(ans, v2 * i + (n - s2 * i) / s1 * v1);
		}
		printf("Case #%d: %lld\n", ++id, ans);
	}

	return 0;
}