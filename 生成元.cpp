/*
���x����x�ĸ�������֮�͵õ�y����ôx����y������Ԫ������n(1<=n<=100000)
����С����Ԫ���޽����0.���磬n=216,121,2005ʱ�Ľ�ֱ�Ϊ198��0��1979
*/
#include<iostream>
#include<cstring>
#define maxn 100005
int main() {
	int ans[maxn]{  };
	for (int i = 1; i < maxn; i++) {
		//ö��������е���������Ԫ��Ȼ����
		int x = i, y = i;
		while (x>0){//�����λ��ӵķ���
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || ans[y] > i) {
			ans[y] = i;
		}
	}
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::cout << ans[n] << std::endl;
	}
	system("pause");
}